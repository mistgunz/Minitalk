all:
	@cd libft && make all
	@gcc -Wall -Wextra -Werror src/server.c libft/libft.a  -o server
	@gcc -Wall -Wextra -Werror src/client.c libft/libft.a  -o client

clean:
	@cd libft && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd libft && make fclean

re: fclean all

bonus: fclean
	@cd libft && make all
	@gcc -Wall -Wextra -Werror "bonus/server_bonus.c" libft/libft.a -o server
	@gcc -Wall -Wextra -Werror "bonus/client_bonus.c" libft/libft.a -o client