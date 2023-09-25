make $1
echo ===========  TEST START  ===========

./fixed_point -0.00321 0.099 mul
./fixed_point -0.00321 1.099 mul
./fixed_point 1 2 mul
./fixed_point 1 0.1 mul
./fixed_point 0 1 mul
./fixed_point 0 0.1 mul

./fixed_point -0.00321 0.099 div
./fixed_point -0.00321 1.099 div
./fixed_point 1 2 div
./fixed_point 1 2 div
./fixed_point 1 0.1 div
./fixed_point 0 1 div
./fixed_point 0 0.1 div


echo ===========  TEST FINISH ===========
make fclean
