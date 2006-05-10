SHELL = /bin/sh

# .SUFFIXES:
.SUFFIXES: .cpp .o

ALL = $(BINDIR)/Evolufit
BINDIR = bin
OBJDIR = ./build
CPPDIR = implementation

DIR_EO = ../EO/src
DIR_NOMAD = ../NOMAD
DIR_MPI = /opt/local/include
#DIR_LIB_MPI = /opt/local/lib
#DIR_LIBXML2 = /usr/include/libxml2

LIBDIRS=-L$(DIR_EO) -L$(DIR_EO)/es -L$(DIR_EO)/utils -L$(DIR_NOMAD) #-L$(DIR_LIB_MPI)
LIBS= $(LIBDIRS) -les -leoutils -leo -lnomad -lxml2

#LIBS= $(LIBDIRS) -les -leoutils -leo -lnomad -lxml2 -lz -lpthread -liconv -lm
 
CXXLIBS = $(LIBS) 

#Added Wno-long-long added for MPI
CXXFLAGS = -ansi -pedantic -O3 -Wall -Wno-deprecated -Wno-long-long -g 
#-i$(DIR_LIBXML2)

#CXXFLAGS = -ansi -pedantic -O3 -Wall -Wno-deprecated -g -fast -mcpu=7450

CXX=mpicxx

DOXYGEN = /opt/local/bin/doxygen

EVOOBJS=	$(CPPDIR)/Evolufit.o \
			$(CPPDIR)/NormalEvolufitStarter.o \
			$(CPPDIR)/MPIEvolufitStarter.o \
			$(CPPDIR)/DataTrace.o \
			$(CPPDIR)/FixedParameters.o \
			$(CPPDIR)/XMLString.o 

MODOBJS=	$(CPPDIR)/ModelResults.o \
			$(CPPDIR)/GenesisModelInterface.o \
			$(CPPDIR)/ModelTuningParameters.o

FITOBJS=	$(CPPDIR)/PabloVdVdtMatrix.o \
			$(CPPDIR)/PabloFitnessCalculator.o
			
EXPOBJS=	$(CPPDIR)/FakeExperimentInterface.o

FITTEROBJS=	$(CPPDIR)/NOMADFitterInterface.o \
			$(CPPDIR)/FitterResults.o \
			$(CPPDIR)/truthfunction.o \
			$(CPPDIR)/EOFitterInterface.o \
			$(CPPDIR)/PabloFitterInterface.o \
			$(CPPDIR)/MeshFitterInterface.o \
			$(CPPDIR)/SwarmFitterInterface.o \
			$(CPPDIR)/SwarmFly.o

OBJS = $(MODOBJS) $(FITOBJS) $(EXPOBJS) $(FITTEROBJS) $(EVOOBJS) 

all : $(ALL)

$(BINDIR)/Evolufit : $(OBJS) ; 
	$(CXX) -o $@ $(OBJS) $(CXXLIBS)

$(CPPDIR)/EOFitterInterface.o : $(CPPDIR)/EOFitterInterface.cpp ;
	$(CXX) -c $(CXXFLAGS) -I$(DIR_EO) -o $@ $<

$(CPPDIR)/EOFitness.o : $(CPPDIR)/EOFitness.cpp ;
	$(CXX) -c $(CXXFLAGS) -I$(DIR_EO) -o $@ $<

$(CPPDIR)/NOMADFitterInterface.o : $(CPPDIR)/NOMADFitterInterface.cpp ;
	$(CXX) -c $(CXXFLAGS) -DPARANOMAD -I$(DIR_NOMAD) -o $@ $<

$(CPPDIR)/PabloFitterInterface.o : $(CPPDIR)/PabloFitterInterface.cpp ;
	$(CXX) -c $(CXXFLAGS) -DPARANOMAD -I$(DIR_EO) -I$(DIR_NOMAD) -o $@ $<

$(CPPDIR)/truthfunction.o : $(CPPDIR)/truthfunction.cpp ;
	$(CXX) -c $(CXXFLAGS) -DPARANOMAD -I$(DIR_NOMAD) -o $@ $<

$(CPPDIR)/Evolufit.o : $(CPPDIR)/Evolufit.cpp ;
	$(CXX) -c $(CXXFLAGS) -DPARANOMAD -I$(DIR_EO) -I$(DIR_NOMAD) -o $@ $<

$(CPPDIR)/NormalEvolufitStarter.o : $(CPPDIR)/NormalEvolufitStarter.cpp ;
	$(CXX) -c $(CXXFLAGS) -DPARANOMAD -I$(DIR_EO) -I$(DIR_NOMAD) -o $@ $<

$(CPPDIR)/MPIEvolufitStarter.o : $(CPPDIR)/MPIEvolufitStarter.cpp ;
	$(CXX) -c $(CXXFLAGS) -DPARANOMAD -I$(DIR_EO) -I$(DIR_NOMAD) -o $@ $<

clean : 
	@/bin/rm -rf $(ALL) *.gch *.o implementation/*.o

doc : *.h implementation/*.cpp doxygen.config ; 
	@$(DOXYGEN) doxygen.config

docclean :
	@/bin/rm -rf doc

test :
	@run
