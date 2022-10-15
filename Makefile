# PROJECT NAME
PROJECTNAME=jade

# INCLUDE PATH
INCPATH = ./src

# INCLUDE BIN PATH
BIN = ./bin

# PATH TO COMPILE
MAIN_TEST = ./test/main_test.cc
MAIN = ${INCPATH}/main/main.cc

SRC_BIN_FILE  = ${INCPATH}/log/log.cc
SRC_BIN_FILE += ${BIN}/libfmt.a


INCLUDE = -I${INCPATH}/log


# COMPILER
GCC=/usr/bin/g++-11

# COMPILER FLAG
FLAGS  = -Wall
FLAGS += -Wextra
FLAGS += -std=c++20

# RM PATH
rm=/bin/rm -r bin/*

.PHONU: proj

all: proj

proj:
	${GCC} ${MAIN} ${SRC_BIN_FILE} -o ${BIN}/${PROJECTNAME}.elf ${FLAGS}

clean:
	${rm}

test:
	@echo "[make]: Run test...\n"
	@${GCC} ${MAIN_TEST} ${SRC_BIN_FILE} -o ${BIN}/${PROJECTNAME}_test.elf ${INCLUDE} ${FLAGS}
	@./bin/${PROJECTNAME}_test.elf

	