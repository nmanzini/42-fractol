echo "\n//////// Norming fractol\n"
norminette ./*.c ./*.h 
echo "\n//////// Norming libft\n"
norminette ./libft/*.c ./libft/*.h
echo "\n//////// Making\n"
make re
echo "\n//////// Testing empty\n"
./fractol
echo "\n//////// Testing wrong file\n"
./fractol fractal
echo "\n//////// Testing 4 fractals\n"
./fractol mandelbrot
./fractol julia
./fractol burning_ship
./fractol tricorn
echo "\n//////// Cleaning\n"
make fclean
