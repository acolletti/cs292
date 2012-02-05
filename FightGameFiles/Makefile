###################################################
#
# Makefile for StateConcept
# Creator [Xcode -> Makefile Ver: Feb 14 2007 09:18:41]
# Created: [Sun Feb  5 14:59:36 2012]
#
###################################################

#
# Macros
#

CC = g++
CC_OPTIONS = 
LNK_OPTIONS = 


#
# INCLUDE directories for StateConcept
#

INCLUDE = -I.


#
# Build StateConcept
#

StateConcept : \
		./main.o\
		./Idle.o\
		./FightGame.o\
		./Hit.o\
		./Settings.o\
		./Player.o\
		./AttackUp.o\
		./DefendUp.o\
		./State.o\
		./Stagger.o\
		./Advance.o\
		./AttackMid.o\
		./AttackLow.o\
		./DefendMid.o\
		./DefendLow.o
	$(CC) $(LNK_OPTIONS) \
		./main.o\
		./Idle.o\
		./FightGame.o\
		./Hit.o\
		./Settings.o\
		./Player.o\
		./AttackUp.o\
		./DefendUp.o\
		./State.o\
		./Stagger.o\
		./Advance.o\
		./AttackMid.o\
		./AttackLow.o\
		./DefendMid.o\
		./DefendLow.o\
		-o StateConcept

clean : 
		rm \
		./main.o\
		./Idle.o\
		./FightGame.o\
		./Hit.o\
		./Settings.o\
		./Player.o\
		./AttackUp.o\
		./DefendUp.o\
		./State.o\
		./Stagger.o\
		./Advance.o\
		./AttackMid.o\
		./AttackLow.o\
		./DefendMid.o\
		./DefendLow.o\
		StateConcept

install : StateConcept
		cp StateConcept StateConcept

#
# Build the parts of StateConcept
#


# Item # 1 -- main --
./main.o : main.cpp
	$(CC) $(CC_OPTIONS) main.cpp -c $(INCLUDE) -o ./main.o


# Item # 2 -- Idle --
./Idle.o : Idle.cpp
	$(CC) $(CC_OPTIONS) Idle.cpp -c $(INCLUDE) -o ./Idle.o


# Item # 3 -- FightGame --
./FightGame.o : FightGame.cpp
	$(CC) $(CC_OPTIONS) FightGame.cpp -c $(INCLUDE) -o ./FightGame.o


# Item # 4 -- Hit --
./Hit.o : Hit.cpp
	$(CC) $(CC_OPTIONS) Hit.cpp -c $(INCLUDE) -o ./Hit.o


# Item # 5 -- Settings --
./Settings.o : Settings.cpp
	$(CC) $(CC_OPTIONS) Settings.cpp -c $(INCLUDE) -o ./Settings.o


# Item # 6 -- Player --
./Player.o : Player.cpp
	$(CC) $(CC_OPTIONS) Player.cpp -c $(INCLUDE) -o ./Player.o


# Item # 7 -- AttackUp --
./AttackUp.o : AttackUp.cpp
	$(CC) $(CC_OPTIONS) AttackUp.cpp -c $(INCLUDE) -o ./AttackUp.o


# Item # 8 -- DefendUp --
./DefendUp.o : DefendUp.cpp
	$(CC) $(CC_OPTIONS) DefendUp.cpp -c $(INCLUDE) -o ./DefendUp.o


# Item # 9 -- State --
./State.o : State.cpp
	$(CC) $(CC_OPTIONS) State.cpp -c $(INCLUDE) -o ./State.o


# Item # 10 -- Stagger --
./Stagger.o : Stagger.cpp
	$(CC) $(CC_OPTIONS) Stagger.cpp -c $(INCLUDE) -o ./Stagger.o


# Item # 11 -- Advance --
./Advance.o : Advance.cpp
	$(CC) $(CC_OPTIONS) Advance.cpp -c $(INCLUDE) -o ./Advance.o


# Item # 12 -- AttackMid --
./AttackMid.o : AttackMid.cpp
	$(CC) $(CC_OPTIONS) AttackMid.cpp -c $(INCLUDE) -o ./AttackMid.o


# Item # 13 -- AttackLow --
./AttackLow.o : AttackLow.cpp
	$(CC) $(CC_OPTIONS) AttackLow.cpp -c $(INCLUDE) -o ./AttackLow.o


# Item # 14 -- DefendMid --
./DefendMid.o : DefendMid.cpp
	$(CC) $(CC_OPTIONS) DefendMid.cpp -c $(INCLUDE) -o ./DefendMid.o


# Item # 15 -- DefendLow --
./DefendLow.o : DefendLow.cpp
	$(CC) $(CC_OPTIONS) DefendLow.cpp -c $(INCLUDE) -o ./DefendLow.o


##### END RUN ####
