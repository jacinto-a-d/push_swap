# Nombre del ejecutable final
NAME        = push_swap

# Compilador y Flags (Requeridos por el subject)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Directorios de tu librería
PRINTF_DIR  = ft_printf

# Archivos de librería (nombres basados en tus archivos)
PRINTF      = $(PRINTF_DIR)/libftprintf.a

# Lista de tus archivos fuente de push_swap (Ajusta estos nombres)
SRC         = push_swap.c\

OBJ         = $(SRC:.c=.o)

# Colores para la terminal
GREEN       = \033[0;32m
RESET       = \033[0m

# Regla principal
all: $(NAME)

# Compilación del ejecutable vinculando ambas librerías
$(NAME): $(OBJ) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)push_swap compilado con éxito.$(RESET)"

# Llama al Makefile del ft_printf que me enviaste
$(PRINTF):
	@make -C $(PRINTF_DIR)

# Compilación de objetos .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos temporales
clean:
	@rm -f $(OBJ)
	@echo "Objeto de push_swap eliminado."

# Limpieza total (incluyendo librerías y ejecutable)
fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@echo "Ejecutable y librería eliminados."

# Re-compilación completa
re: fclean all

# Regla para el bonus (checker)
bonus: all
	@# Aquí añadirías la lógica para compilar el programa 'checker'

.PHONY: all clean fclean re bonus