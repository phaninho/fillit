echo "\033[35mTest programme sans parametres :\033[0m"
./fillit
sleep 1
echo "\033[35mTest programme avec trop de parametres\033[0m"
./fillit p p k hud hudh id
sleep 1
echo "\033[35mTest programme avec une piece invalide\033[0m"
./fillit 01_Piece_invalide
sleep 1
echo "\033[35mTest programme avec une piece trop grande\033[0m"
./fillit 01_02_Piece_invalide
sleep 1
echo "\033[35mTest programme avec une piece trop petite\033[0m"
./fillit 01_03_Piece_invalide
sleep 1
echo "\033[35mTest programme avec un fichier valide\033[0m"
./fillit test1.prm
sleep 1
echo "\033[35mTest programme avec un fichier mal formate\033[0m"
./fillit 02_01_Fichier_invalide
sleep 1
echo "\033[35mTest programme avec un fichier vide\033[0m"
./fillit 02_2_fichier_vide
sleep 1
echo "\033[35mTout est la ou il faut, comme il faut\033[0m"
./fillit 03_Tout_est_la_ou_il_faut_comme_il_faut
sleep 1
echo "\033[35mBonus moin de 1 seconde\033[0m"
time ./fillit test7.prm
sleep 1
echo "\033[35mTest perso (Hors Correction)\033[0m"
time ./fillit Bonus
