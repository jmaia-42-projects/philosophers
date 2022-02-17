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

SRCS		=	$(addprefix not_libft/, $(SRCS_NOT_LIBFT)) \
				get_timestamp.c \
				live.c \
				main.c \
				parse_args.c \
				philosophize.c

_OBJS		=	${SRCS:.c=.o}
OBJS		=	$(addprefix build/, $(_OBJS))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -pthread
INCLUDE		=	-I includes/
LIBS		=


all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	$(OBJS) | libs
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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

reall	: relibs re


.PHONY	:	all libs clean cleanlibs cleanall fclean fcleanlibs fcleanall re relibs reall
