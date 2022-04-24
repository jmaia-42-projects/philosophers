NAME		=	philo_bonus

SRCS_NOT_LIBFT	=	ft_atoi.c \
					ft_isdigit.c \
					ft_isint.c \
					ft_isnbr.c \
					ft_isspace.c \
					ft_itoa.c \
					ft_itoa_base.c \
					ft_strcmp.c \
					ft_strlen.c \
					ft_strncmp.c

SRCS		=	\
				$(addprefix not_libft/, $(SRCS_NOT_LIBFT)) \
				actions/do_action.c \
				actions/ph_eat.c \
				actions/ph_fork.c \
				actions/ph_sleep.c \
				actions/ph_think.c \
				did_philo_starve_to_death.c \
				main.c \
				free_forks.c \
				ft_wait.c \
				init_forks.c \
				init_philos.c \
				live.c \
				parse_args.c \
				start_simulation.c \
				utils/ft_strcpy.c \
				utils/nbrlen.c \
				utils/timeval_ops.c \
				wait_philos.c

_OBJS		=	${SRCS:.c=.o}
OBJS		=	$(addprefix build/, $(_OBJS))

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -pthread
INCLUDE		=	-I includes/
LIBS		=


all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	$(OBJS) | libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libs	:
	@for lib in $(LIBS); do\
		echo make -C $$(dirname $$lib);\
		make -C $$(dirname $$lib);\
	done

clean	:	
	rm -Rf build/

cleanlibs	:
	@for lib in $(LIBS); do\
		echo make -C $$(dirname $$lib) clean;\
		make -C $$(dirname $$lib) clean;\
	done

cleanall	:	clean cleanlibs


fclean	:	clean
	rm -f ${NAME}

fcleanlibs	:
	@for lib in $(LIBS); do\
		echo make -C $$(dirname $$lib) fclean;\
		make -C $$(dirname $$lib) fclean;\
	done

fcleanall	:	fclean fcleanlibs


re		:	fclean ${NAME}

relibs	:
	@for lib in $(LIBS); do\
		echo make -C $$(dirname $$lib) re;\
		make -C $$(dirname $$lib) re;\
	done

reall	: relibs re

bonus	:	all


.PHONY	:	all libs clean cleanlibs cleanall fclean fcleanlibs fcleanall re relibs reall bonus
