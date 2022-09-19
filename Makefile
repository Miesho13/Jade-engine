# PROJECT NAME
PROJECTNAME=JADE

#PATH TO COMPILE
BILDPATH=./bin/

#SRC PATH
SRC=./src/

#OBJECT TO COMPILE
ALLOBJ=""

# COMPILER
GCC=/usr/bin/g++-10
FLAGS=-Wall -Wextra -I "./src/"


# RM PATH
rm=/bin/rm -r ./bin/*

all:
	${GCC} main.cc ${ALLBOJ} ${FLAGS} -o ${BILDPATH}${PROJECTNAME}

allobj:
	${GCC} -c ${SRC}log/log.cc ${FLAGS} -o ${BILDPATH}log 


clear:
	${rm}

test:
  ${GCC test/main_test.cc 
	