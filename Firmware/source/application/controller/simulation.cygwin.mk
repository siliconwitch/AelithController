# For simulation run-time library
SIM_CFLAGS =
SIM_INCLUDES = -I$(LVPATH_CYG)/cintools

SIM_PATH = $(LVPATH_CYG)/CCodeGen/Simulation

-include solvers.mk

vpath %.c $(SIM_PATH)

SIM_SRCS = $(notdir $(wildcard $(LVPATH_CYG)/CCodeGen/Simulation/*.c)) \
$(SOLVER_SRCS)

SIM_OBJDIR = simobj
SIM_OBJS = $(patsubst %.c,$(SIM_OBJDIR)/%.o,$(SIM_SRCS))

$(SIM_OBJDIR)/%.o: %.c LVFuncsUsed.h LVForms.h LVGlobs.h
	@mkdir -p $(SIM_OBJDIR)
	@$(CC) -c $(CFLAGS) $(SIM_CFLAGS) $(INCLUDES) $(SIM_INCLUDES) -o $@ $<
	@echo $(notdir $<)

clean: sim_clean

sim_clean:
	rm -f $(SIM_OBJS)
