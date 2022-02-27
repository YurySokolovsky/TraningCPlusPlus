# Создание и сборка Custom Transformation  

## Создание Custom Transformation  
Создание Сustome Transformation осуществляется в соответствии с **Help -> Transformation Guide -> Creating Custome Transformation Procedure**.
Для создания Custome Transformation следует в Informatica Power Center Designer:
1. Выбрать **Tools -> Transformation Developer**. В результате появится меню создания трансформаций, разблокируется панель инструментов, для создания трансформаций;
2. Выбрать в меню **Tranformation -> Create** и в выпадающем списке появившегося окна нажать **Custome Transformation** или нажать иконку **Custome Transformation** на панели инструментов и выделить область в поле **Transformation Designer**; 
3. В диалоговом окне «Active or Passive» выбрать тип (по умолчанию Active). В выпадающем списке выбрать язык *С*, т.к. опция генерации кода не срабатывает для *С++* и нажать «ОК»;
4. Открыть Custome Transformation и перейти на вкладку «**Ports**». Создать группы c помощью панели инст рументов (**Create Input Group**, **Create Output Group**) и порты (**Add a new port to this transformation**). Так же  можно отредактировать группы и порты при необходимости позже c помощью команды **Edit**, появляющейся при нажатии правой клаишей на Custome Transformation; 
5. Выбрать вкладку «**Properties**» и ввести **Module Identifier** и **Function Identifier**, а также **Runtime Location**;
6. Отредактировать другие атрибуты свойств трансформации:
- **Metadata Extensions**, чтобы ввести расширения метаданных ( например свойства, которые могут потребоваться внешней процедуре для инициализации)
- **Port Attribute Definitions**, чтобы создать атрибуты порта, если это необходимо.

## Создание файлов C
После создания Custome Transformation необходимо создать файлы исходного кода. Чтобы сгенерировать код для Custome Transformation следует:
1. Находясь в Transformation Developer выбрать **Transformation -> Generate Code**;
2. В диалоговом окне **External Procedure Stub Generation** выбрать только что созданную процедуру и директорию, в которой вы хотите сгенерировать файлы, и нажать **Generate**.

Transformation Developer создает подкаталог c именем модуля в указанной директории c файлами:

`m_<Custom Transformation Name>.c`  
  
`m_<Custom Transformation Name>.h` 
 
`p_<Custom Transformation Name>.c`  

`p_<Custom Transformation Name>.h`  

а так же `makefile.linux` (32-разрядная версия) и  makefile-ы для других типов операционных систем.

## Заполнение кодом с логикой трансформации
Необходимо написать код для файла *C++* процедуры. Так же можно написать код файла *C++* модуля. 
Чтобы закодировать файл *C++* процедуры трансформации следует:
1. Переименовать полученные файлы `.с` в `.сpp` файлы.
1. Открыть `p_<Custom Transformation Name>.cpp` для процедуры;
2. Написать код *C++* для процедуры;
3. Сохранить измененный файл.
4. При необходимости сделать тоже самое для файла модуля *С++*.

==========================

## Создание модуля
Можно собрать модуль на платформах Windows или Linux.
### Сборка модуля в Windows
В Windows сборку модуля можно осущестить используя Microsoft Visual Studio (использовалась Microsoft Visual Studio Professional 2019).
Чтобы собрать модуль в Windows:
1. Запустить Microsoft Visual Studio;
2. Выбрать  **Create a new project**;
3. В диалоговом окне **Create a new project** выбрать **Dynamic-Link Library(DLL)** и нажать **Next**;
4. В диалоговом окне **Configure your new project** ввести имя проекта и решения, выбрать директорию для расположения проекта и нажать **Create**. В качестве имени проекта необходимо использовать имя модуля, указанное для Custome Tranformation;
5. Скопировать в директорию с файлами проекта файлы модуля и процедуры `.h` и `.cpp.
6. В **Solution Explorer** выбрать созданный проект, правым щелчком на **Header Files** в всплывающем меню выбрать **Add -> Existing Item...**. В появившемся диалоговом окне выбрать `.h`-файлы модуля и процедуры и нажать кнопку **Add**;
7. Повторить процедуру для `.cpp`-файлов. Правым щелчком мыши на **Source Files** в всплывающем меню выбрать **Add -> Existing Item...**. В появившемся диалоговом окне выбрать `.cpp`-файлы модуля и процедуры и нажать кнопку **Add**;
8. Нажатием правой клавиши фыши на проекте в всплывающем меню выбрать **Properties**. В появившемся диалоговом окне выбрать **Configuration Properties -> C/C++ -> General**. В пунке **Additional Iclude Directories** выбрать директорию содержащую файлы `сh\userproc_c.h` и `сh\usermodule_c.h ` (в нашем случае это `С:\Informatica\10.5.1\clients\tools\utils\ExtProc\include`)
9. При необходимости указать в **Configuration Properties -> General** указать версию стандарта *С++*.
10. В сгенерировванный при создании проекта файл `pch.h` добавить:
`#ifdef WIN32`
`#include "framework.h"`
`#endif`
11. Добавить в файлы `.cpp` процедуры и модуля `#include "pch.h"`
12. В меню выбрать **Build -> Build Solution**, после чего Microsoft Visual Studio создает библиотеку DLL и помещает ее в подкаталог Debug или Release в каталоге проекта.

### Сборка модуля в Linux
В Linux используйте компилятор C++ для сборки модуля.
Чтобы собрать модуль в Linux необходимо:  
1. Скопировать все файлы C++ и `makefile.linux`, созданный в Informatica Power Center DesignerDesigner, на cервер с Linux;
2. Внести следующие изменения в makefile.linux:
+ указать стандарт языка, заменив `FLAGS=-Wall -fPIC -DUNIX` на `FLAGS=std=c++11 -Wall -fPIC -DUNIX`;
+ заменить `.SUFFIXES : .c` на `.SUFFIXES : .cpp`
+ заменить `.с.o : ;$(CC) -c $(FLAGS) $(DEFINE) $(INCLUDEDIRS) $*.c -o $*.o` на `.сpp.o : ;$(CC) -c $(FLAGS) $(DEFINE) $(INCLUDEDIRS) $*.cpp -o $*.o` 
+ заменить `OBJS=$(SRCS:%.c=%.o)`на `OBJS=$(SRCS:%.cpp=%.o)`
+ в строках `SRCS = \...` заменить расширения файлов с `.с` на `.cpp`.
3. В терминале задать для переменной среды `PM_HOME` каталог установки службы интеграции: 
`$ export PM_HOME = /informatica/10.5.1/server/bin`
4. Ввести команду make, находясь в папке с `makefile.linux`,чтобы создать проект:  
`$ make -f makefile.linux`  
***Примечание 1.*** Если требуется создать shared library на компьютере, отличном от сервера службы интеграции, следует скопировать файлы из каталога на компьютер на котором осуществляеся сборка.  
***Примечание 2.*** Если вы укажете неверный путь к каталогу для переменной среды PM_HOME, служба интеграции не запустится.

==================

## Создание Mapping
1. Выбрать **Tools -> Mapping Designer**. В списке каталогов выбрать папку и в ней выбрать подкаталог Mappings. 
2. В Mapping Designer выберите **Mappings -> Create** и создайте Mapping, использующий  Custome Transformation.
В Mapping источник (источники) данных подключается к входным портам входных групп (Input Group) в Custome Transformation.
Источник данных выбирается из уже существующих или может быть создан с помощью **Tools -> Source Analyzer**.
3. Создать Target для Custome Transformation нажав правой клавшей на трансформацию и выбрав Create and Add Target или с помощью Tool -> Target Designer, добавив его после в Mapping. 
   
Custome Transformation  берет данные из источника (источников) и выводит результат трансформации через порты выходной группы (Output Group). Данные из Custome Transformation попадают в результат трансформации (Target).
При этом в Mapping должны быть **Source Inctances, Target Instances, Transformation Instances** (отображаются в соответствующих каталогах в созданном Mapping), в противном случае Mapping не пройдет валидацию и его нельзя будет использовать для создания или включения в рабочий процесс (Workflow).

## Запустите сессию (Session) в рабочем процессе (Workflow)
Когда вы запускаете Session, служба интеграции ищет общую библиотеку или библиотеку DLL в расположении среды выполнения (runtime), указанном вами в Custome Transformation.

Чтобы запустить Session в Workflow:
1. В Workflow Manager создайте Workflow.
2. Создайте Session для этого Mapping-a в Workflow.
3. Скопируйте динамическую библиотеку (.so) или DLL в каталог расположения среды выполнения (Runtime).
4. Запустите Workflow, содержащий Session.

Когда Integration Service загружает Custome Transformation, связанное с процедурой, она загружает библиотеку DLL или динамичекую библиотеку(.so) и вызывает определенную вами процедуру.


