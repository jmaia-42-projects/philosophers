NAME		=	philo

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
LIBS		=	libs/mind/mind.a


all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

<<<<<<< HEAD
$(NAME)	:	$(addprefix build/,${OBJS}) libs
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

libs	:
	@for lib in $(LIBS); do\
		make -C $((dirname $$lib);\
=======
$(NAME)	:	$(OBJS) | libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libs	:
	@for lib in $(LIBS); do\
		echo make -C $$(dirname $$lib);\
		make -C $$(dirname $$lib);\
>>>>>>> bonus2
	done

clean	:	
	rm -Rf build/

cleanlibs	:
	@for lib in $(LIBS); do\
<<<<<<< HEAD
		make -C $((dirname $$lib) clean;\
=======
		echo make -C $$(dirname $$lib) clean;\
		make -C $$(dirname $$lib) clean;\
>>>>>>> bonus2
	done

cleanall	:	clean cleanlibs


fclean	:	clean
	rm -f ${NAME}

fcleanlibs	:
	@for lib in $(LIBS); do\
<<<<<<< HEAD
		make -C $((dirname $$lib) fclean;\
=======
		echo make -C $$(dirname $$lib) fclean;\
		make -C $$(dirname $$lib) fclean;\
>>>>>>> bonus2
	done

fcleanall	:	fclean fcleanlibs


re		:	fclean ${NAME}

relibs	:
<<<<<<< HEAD
=======
	@for lib in $(LIBS); do\
		echo make -C $$(dirname $$lib) re;\
		make -C $$(dirname $$lib) re;\
	done
>>>>>>> bonus2

reall	: relibs re


.PHONY	:	all libs clean cleanlibs cleanall fclean fcleanlibs fcleanall re relibs reall
