%Ripulisce la command window
clc

%Stampa diverse portate
disp("Menu' del giorno:");
disp("1. Spaghetti alle vongole.");
disp("2. Frittura mista.");
disp("3. Cozze gratinate.");
disp("4. Tiramisu'.");

%Prende in input un numero intero, associato a una delle portate
value = input("Inserire il numero di una delle 4 portate: ");

%In base al valore inserito, verrà svolta una di queste operazioni
switch value
    case 1
        disp("Spaghetti alle vongole, 330kcal.");
    case 2
        disp("Frittura mista, 395kcal.");
    case 3
        disp("Cozze gratinate, 390kcal.");
    case 4
        disp("Tiramisu', 492kcal.");
    otherwise
        disp("Attenzione, hai scelto una portata non esistente.");
end
