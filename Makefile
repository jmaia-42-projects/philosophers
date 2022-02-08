NAME		=	

_SRCS		=	
SRCS		=	$(addprefix srcs/, $(_SRCS))

OBJS		=	${SRCS:.c=.o}

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDE		=	-I includes/
LIBS		=	pouet/pouetouille/hey.a


all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	$(addprefix build/,${OBJS}) libs
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

libs	:
	@for lib in $(LIBS); do\
		make -C $((dirname $$lib);\
	done

clean	:	
	rm -Rf build/

cleanlibs	:
	@for lib in $(LIBS); do\
		make -C $((dirname $$lib) clean;\
	done

cleanall	:	clean cleanlibs


fclean	:	clean
	rm -f ${NAME}

fcleanlibs	:
	@for lib in $(LIBS); do\
		make -C $((dirname $$lib) fclean;\
	done

fcleanall	:	fclean fcleanlibs


re		:	fclean ${NAME}

relibs	:

reall	: relibs re


.PHONY	:	all libs clean cleanlibs cleanall fclean fcleanlibs fcleanall re relibs reall
