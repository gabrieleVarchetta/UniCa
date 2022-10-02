% Ripulisce la command window
clc

% Si chiede di inserire un valore in input e lo si salva nella variabile
% value
value = input("Inserisci un valore tra 0 e 50: ");

% Se il valore inserito è compreso tra 0 e 5
if(value >= 0 && value <= 50)
    % Calcolo la sua radice quadrata e stampo il risultato
    rad = sqrt(value);
    disp("La radice quadrata del numero inserito è: ");
    disp(rad);
else
    % Altrimenti stampo un messaggio di errore
    disp("Il valore inserito non e' nel range accettato.");
end

