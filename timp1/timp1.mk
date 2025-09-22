##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=timp1
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/stud/C++Projects/Education
ProjectPath            :=/home/stud/C++Projects/Education/timp1
IntermediateDirectory  :=../build-$(ConfigurationName)/timp1
OutDir                 :=../build-$(ConfigurationName)/timp1
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=09/22/25
CodeLitePath           :=/home/stud/.codelite
LinkerName             :=/usr/bin/g++-10
SharedObjectLinkerName :=/usr/bin/g++-10 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-10
CC       := /usr/bin/gcc-10
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/timp1/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/timp1/modAlphaCipher.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/timp1/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/timp1"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/timp1"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/timp1/.d:
	@mkdir -p "../build-$(ConfigurationName)/timp1"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/timp1/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/timp1/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Education/timp1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/timp1/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/timp1/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/timp1/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/timp1/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/timp1/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/timp1/modAlphaCipher.cpp$(ObjectSuffix): modAlphaCipher.cpp ../build-$(ConfigurationName)/timp1/modAlphaCipher.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Education/timp1/modAlphaCipher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modAlphaCipher.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/timp1/modAlphaCipher.cpp$(DependSuffix): modAlphaCipher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/timp1/modAlphaCipher.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/timp1/modAlphaCipher.cpp$(DependSuffix) -MM modAlphaCipher.cpp

../build-$(ConfigurationName)/timp1/modAlphaCipher.cpp$(PreprocessSuffix): modAlphaCipher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/timp1/modAlphaCipher.cpp$(PreprocessSuffix) modAlphaCipher.cpp


-include ../build-$(ConfigurationName)/timp1//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


