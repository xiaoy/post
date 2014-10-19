c1y=clang++ -std=c++1y

objects=main.o player.o PlayerStandState.o PlayerAttackState.o PlayerMoveState.o PlayerDieState.o StateManager.o
all=main

main:${objects}
	${c1y} -o $@ ${objects}
main.o:main.cc
	${c1y} -c $<

player.o:player.cc
	${c1y} -c $<

PlayerStandState.o:PlayerStandState.cc
	${c1y} -c $<

PlayerMoveState.o:PlayerMoveState.cc
	${c1y} -c $<

PlayerAttackState.o:PlayerAttackState.cc
	${c1y} -c $<

PlayerDieState.o:PlayerDieState.cc
	${c1y} -c $<

StateManager.o:StateManager.cc
	${c1y} -c $<

clean:
	rm *.o ${all}
