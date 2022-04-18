NAME		=	mind.a

SRCS		=	\
				lists/ft_lstadd_front.c \
				lists/ft_lstnew.c \
				mind_add.c \
				mind_blow.c \
				mind_free.c \
				mind_init.c \
				mind_malloc.c \
				mind_remove.c

_OBJS		=	${SRCS:.c=.o}
OBJS		=	$(addprefix build/, $(_OBJS))
DEPS		=	$(OBJS:%.o=%.d)


AR			=	ar
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDE		=	\
				-I includes/

LIBS		=
LIBS_EXT	=


all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	$(OBJS) $(LIBS)
	$(AR) -rc $(NAME) $(OBJS)

$(LIBS)	:	FORCE
	@for lib in $(LIBS); do\
		echo $(MAKE) -C $$(dirname $$lib);\
		$(MAKE) -C $$(dirname $$lib);\
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


bonus	:	$(NAME)

.PHONY	:	all clean cleanlibs cleanall fclean fcleanlibs fcleanall re relibs reall FORCE bonus
