##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=jsonP_dyn
ConfigurationName      :=Debug
WorkspacePath          :=/Users/user1/udemy/CPP/UdemyCPP
ProjectPath            :=/Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn
IntermediateDirectory  :=/Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=User One
Date                   :=01/10/2019
CodeLitePath           :="/Users/user1/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -dynamiclib -fPIC
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
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).dylib
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="jsonP_dyn.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/element_object.cpp$(ObjectSuffix) $(IntermediateDirectory)/jsonP_parser.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "/Users/user1/udemy/CPP/UdemyCPP/.build-debug"
	@echo rebuilt > "/Users/user1/udemy/CPP/UdemyCPP/.build-debug/jsonP_dyn"

MakeIntermediateDirs:
	@test -d /Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn/Debug || $(MakeDirCommand) /Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn/Debug


$(IntermediateDirectory)/.d:
	@test -d /Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn/Debug || $(MakeDirCommand) /Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn/Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/element_object.cpp$(ObjectSuffix): element_object.cpp $(IntermediateDirectory)/element_object.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn/element_object.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/element_object.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/element_object.cpp$(DependSuffix): element_object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/element_object.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/element_object.cpp$(DependSuffix) -MM element_object.cpp

$(IntermediateDirectory)/element_object.cpp$(PreprocessSuffix): element_object.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/element_object.cpp$(PreprocessSuffix) element_object.cpp

$(IntermediateDirectory)/jsonP_parser.cpp$(ObjectSuffix): jsonP_parser.cpp $(IntermediateDirectory)/jsonP_parser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn/jsonP_parser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jsonP_parser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jsonP_parser.cpp$(DependSuffix): jsonP_parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jsonP_parser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/jsonP_parser.cpp$(DependSuffix) -MM jsonP_parser.cpp

$(IntermediateDirectory)/jsonP_parser.cpp$(PreprocessSuffix): jsonP_parser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jsonP_parser.cpp$(PreprocessSuffix) jsonP_parser.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r /Users/user1/udemy/CPP/UdemyCPP/jsonP_dyn/Debug/

