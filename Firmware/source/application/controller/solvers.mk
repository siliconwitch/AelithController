
SOLVER_PATH = $(SIM_PATH)/Solvers

vpath %.c $(SOLVER_PATH)/AdamsBM
vpath %.c $(SOLVER_PATH)/DAESolver
vpath %.c $(SOLVER_PATH)/DAESolver/DASSL
vpath %.c $(SOLVER_PATH)/ExplicitRK
vpath %.c $(SOLVER_PATH)/ExplicitRK/RKFixed2
vpath %.c $(SOLVER_PATH)/ExplicitRK/RKFixed3
vpath %.c $(SOLVER_PATH)/ExplicitRK/RKFixed4
vpath %.c $(SOLVER_PATH)/ExplicitRK/RKVariable23
vpath %.c $(SOLVER_PATH)/ExplicitRK/RKVariable45
vpath %.c $(SOLVER_PATH)/GearBrown
vpath %.c $(SOLVER_PATH)/RadauIIa
vpath %.c $(SOLVER_PATH)/RadauIIa/RadauIIa1
vpath %.c $(SOLVER_PATH)/RadauIIa/RadauIIa5
vpath %.c $(SOLVER_PATH)/RadauIIa/RadauIIa9
vpath %.c $(SOLVER_PATH)/RadauIIa/RadauIIa13
vpath %.c $(SOLVER_PATH)/RadauIIa/RadauIIaV
vpath %.c $(SOLVER_PATH)/Rosenbrock
vpath %.c $(SOLVER_PATH)/Rosenbrock/Ros2_g293
vpath %.c $(SOLVER_PATH)/SDIRK
vpath %.c $(SOLVER_PATH)/SDIRK/SDIRK4_g267
vpath %.c $(SOLVER_PATH)/Utils

SOLVER_SRCS = \
$(notdir $(wildcard $(SOLVER_PATH)/AdamsBM/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/DAESolver/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/DAESolver/DASSL/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/ExplicitRK/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/ExplicitRK/RKFixed2/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/ExplicitRK/RKFixed3/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/ExplicitRK/RKFixed4/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/ExplicitRK/RKVariable23/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/ExplicitRK/RKVariable45/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/GearBrown/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/RadauIIa/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/RadauIIa/RadauIIa1/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/RadauIIa/RadauIIa5/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/RadauIIa/RadauIIa9/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/RadauIIa/RadauIIa13/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/RadauIIa/RadauIIaV/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/Rosenbrock/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/Rosenbrock/Ros2_g293/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/SDIRK/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/SDIRK/SDIRK4_g267/*.c)) \
$(notdir $(wildcard $(SOLVER_PATH)/Utils/*.c))

