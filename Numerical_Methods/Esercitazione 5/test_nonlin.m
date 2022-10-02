% Help:
%Lo script effettua dei test nella risoluzione di alcune equazioni non
%lineari con i quattro metodi visti a lezione (Bisezione, Newton, Corde e
%Secanti). I dati utilizzati per svolgere i test sono stati presi dalle
%tabelle 7.1, 7.2, 7.3 e 7.4 del libro di testo

clc
warning('off');

% Tabella 7.1 (metodo bisezione)
fprintf("Metodo Bisezione\n\n");
fprintf("f(x)          a          [a,b]          |x-a|          n.iter.\n");
fprintf("______________________________________________________________\n");

% prima funzione
f1 = @(x) x^2 - 2;
a = 0;
b = 2;
x = sqrt(2);
[c, k] = bisec(f1, a, b, 1e-8, 100);
fprintf("x^2 - 2    %.2d      [%d,%d]         %.1d           %d\n", x, a, b, abs(c-x),k);

a = 0;
b = 200;
[c, k] = bisec(f1, a, b, 1e-8, 100);
fprintf("x^2 - 2    %.2d     [%d,%d]        %.1d           %d\n", x, a, b, abs(c-x),k);

% seconda funzione
f1 = @(x) exp(x) - 2;
a = 0;
b = 2;
x = log(2);
[c, k] = bisec(f1, a, b, 1e-8, 100);
fprintf("e^x - 2    %.2d      [%d,%d]         %.1d           %d\n", x, a, b, abs(c-x),k);

a = 0;
b = 200;
[c, k] = bisec(f1, a, b, 1e-8, 100);
fprintf("e^x - 2    %.2d     [%d,%d]        %.1d           %d\n", x, a, b, abs(c-x),k);

% terza funzione
f1 = @(x) (1/x) - 3;
a = 0;
b = 2;
x = 1/3;
[c, k] = bisec(f1, a, b, 1e-8, 100);
fprintf("1/x - 3    %.2d      [%d,%d]         %.1d           %d\n", x, a, b, abs(c-x),k);

a = 0;
b = 200;
[c, k] = bisec(f1, a, b, 1e-8, 100);
fprintf("1/x - 3    %.2d     [%d,%d]        %.1d           %d\n", x, a, b, abs(c-x),k);

% quarta funzione
f1 = @(x) (x-3)^3;
a = 4/3;
b = 10/3;
x = 3;
[c, k] = bisec(f1, a, b, 1e-8, 100);
fprintf("(x-3)^3       %d         [%.1f,%.1f]      %.1d           %d\n", x, a, b, abs(c-x),k);

a = 4/3;
b = 604/3;
[c, k] = bisec(f1, a, b, 1e-8, 100);
fprintf("(x-3)^3       %d        [%.1f,%.1f]     %.1d           %d\n", x, a, b, abs(c-x),k);

% Tabella 7.2 (metodo newton)
fprintf("\n\nMetodo Newton\n\n");
fprintf("f(x)          a          x0          |x-a|          n.iter.\n");
fprintf("______________________________________________________________\n");

% prima funzione
f1 = @(x) x^2 - 2;
fd1 = @(x) 2*x ;
x0 = 2;
x = sqrt(2);
[c, k] = newton(f1, fd1, x0, 1e-8, 100);
fprintf("x^2 - 2    %.2d       %d             %.1d              %d\n", x, x0, abs(c-x),k);

x0 = 200;
[c, k] = newton(f1, fd1, x0, 1e-8, 100);
fprintf("x^2 - 2    %.2d     %d             %.1d             %d\n", x, x0, abs(c-x),k);

% seconda funzione
f1 = @(x) exp(x) - 2;
fd1 = @(x) exp(x) ;
x0 = 2;
x = log(2);
[c, k] = newton(f1, fd1, x0, 1e-8, 100);
fprintf("e^x - 2    %.2d       %d             %.1d              %d\n", x, x0, abs(c-x),k);

x0 = 200;
[c, k] = newton(f1, fd1, x0, 1e-8, 100);
fprintf("e^x - 2    %.2d     %d          %.1d         %d\n", x, x0, abs(c-x),k);

% terza funzione
f1 = @(x) (1/x) - 3;
fd1 = @(x) -(1/(x^2));
x0 = 2;
x = 1/3;
[c, k] = newton(f1, fd1, x0, 1e-8, 100);
fprintf("1/x - 3    %.2d       %d            %.1d            %d\n", x, x0, abs(c-x),k);

x0 = 0.1;
[c, k] = newton(f1, fd1, x0, 1e-8, 100);
fprintf("1/x - 3    %.2d       %.1f        %.1d           %d\n", x, x0, abs(c-x),k);

% quarta funzione
f1 = @(x) (x-3)^3;
fd1 = @(x) 3*(x-3)^2;
x0 = 2;
x = 3;
[c, k] = newton(f1, fd1, x0, 1e-8, 100);
fprintf("(x-3)^3       %d           %d          %.1d          %d\n", x, x0, abs(c-x),k);

x0 = 2.9;
[c, k] = newton(f1, fd1, x0, 1e-8, 100);
fprintf("(x-3)^3       %d           %.1f        %.1d          %d\n", x, x0, abs(c-x),k);

% Tabella 7.3 (metodo corde)
fprintf("\n\nMetodo Corde\n\n");
fprintf("f(x)          a          x0          |x-a|          n.iter.\n");
fprintf("______________________________________________________________\n");

% prima funzione
f1 = @(x) x^2 - 2;
fd1 = @(x) 2*x;
x0 = 2;
m = fd1(x0) ;
x = sqrt(2);
[c, k] = corde(f1, m, x0, 1e-8, 2000);
fprintf("x^2 - 2    %.2d       %d          %.1d           %d\n", x, x0, abs(c-x),k);

x0 = 200;
m = fd1(x0) ;
[c, k] = corde(f1, m, x0, 1e-8, 2000);
fprintf("x^2 - 2    %.2d     %d          %.1d         %d\n", x, x0, abs(c-x),k);

% seconda funzione
f1 = @(x) exp(x) - 2;
fd1 = @(x) exp(x);
x0 = 2;
m = fd1(x0) ;
x = log(2);
[c, k] = corde(f1, m, x0, 1e-8, 2000);
fprintf("e^x - 2    %.2d       %d          %.1d           %d\n", x, x0, abs(c-x),k);

x0 = 200;
m = fd1(x0);
[c, k] = corde(f1, m, x0, 1e-8, 2000);
fprintf("e^x - 2    %.2d     %d          %.1d         %d\n", x, x0, abs(c-x),k);

% terza funzione
f1 = @(x) (1/x) - 3;
fd1 = @(x) -1/(x)^2;
x0 = 2;
m = fd1(x0) ;
x = 1/3;
[c, k] = corde(f1, m, x0, 1e-8, 2000);
fprintf("1/x - 3    %.2d       %d          %.1d         %d\n", x, x0, abs(c-x),k);

x0 = 0.1;
m = fd1(x0);
[c, k] = corde(f1, m, x0, 1e-8, 2000);
fprintf("1/x - 3    %.2d       %.1f        %.1d          %d\n", x, x0, abs(c-x),k);

% quarta funzione
f1 = @(x) (x-3)^3;
fd1 = @(x) 3*(x-3)^2;
x0 = 2;
m = fd1(x0) ;
x = 3;
[c, k] = corde(f1, m, x0, 1e-8, 2000);
fprintf("(x-3)^3       %d           %d          %.1d         %d\n", x, x0, abs(c-x),k);

x0 = 2.9;
m = fd1(x0);
[c, k] = corde(f1, m, x0, 1e-8, 2000);
fprintf("(x-3)^3       %d           %.1f        %.1d         %d\n", x, x0, abs(c-x),k);

% Tabella 7.2 (metodo secanti)
fprintf("\n\nMetodo Secanti\n\n");
fprintf("f(x)          a          [a,b]          |x-a|          n.iter.\n");
fprintf("______________________________________________________________\n");

% prima funzione
f1 = @(x) x^2 - 2;
x0 = 1;
x1 = 2;
x = sqrt(2);
[c, k] = secanti(f1, x0, x1, 1e-8, 100);
fprintf("x^2 - 2    %.2d      [%d,%d]         %.1d           %d\n", x, x0, x1, abs(c-x),k);

x0 = 199;
x1 = 200;
[c, k] = secanti(f1, x0, x1, 1e-8, 100);
fprintf("x^2 - 2    %.2d    [%d,%d]       %.1d          %d\n", x, x0, x1, abs(c-x),k);

% seconda funzione
f1 = @(x) exp(x) - 2;
x0 = 2;
x1 = 3;
x = log(2);
[c, k] = secanti(f1, x0, x1, 1e-8, 100);
fprintf("e^x - 2    %.2d      [%d,%d]         %.1d           %d\n", x, x0, x1, abs(c-x),k);

x0 = 199;
x1 = 200;
[c, k] = secanti(f1, x0, x1, 1e-8, 100);
fprintf("e^x - 2    %.2d    [%d,%d]       %.1d         %d\n", x, x0, x1, abs(c-x),k);

% terza funzione
f1 = @(x)1/x - 3;
x0 = 2;
x1 = 3;
x = 1/3;
[c, k] = secanti(f1, x0, x1, 1e-8, 100);
fprintf("1/x - 3    %.2d      [%d,%d]           %.1d             %d\n", x, x0, x1, abs(c-x),k);

x0 = 0.1;
x1 = 0.11;
[c, k] = secanti(f1, x0, x1, 1e-8, 100);
fprintf("1/x - 3    %.2d    [%.1f,%.2f]      %.1d           %d\n", x, x0, x1, abs(c-x),k);

% quarta funzione
f1 = @(x) (x - 3)^3;
x0 = 1;
x1 = 2;
x = 3;
[c, k] = secanti(f1, x0, x1, 1e-8, 100);
fprintf("(x-3)^3       %d          [%d,%d]         %.1d          %d\n", x, x0, x1, abs(c-x),k);

x0 = 2.5;
x1 = 2.9;
[c, k] = secanti(f1, x0, x1, 1e-8, 100);
fprintf("(x-3)^3       %d        [%.1f,%.1f]       %.1d          %d\n", x, x0, x1, abs(c-x),k);