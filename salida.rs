fn hanoi (char  hacia, char  auxiliar, char  desde, i32  n) {
if (n == 1){
	print!("Mueva el disco 1 desde el poste %c hacia el poste %c\n{}",desde,hacia);
return;
}
print!("aqui1");
hanoi(n - 1,desde,hacia,auxiliar);
print!("Mueva el disco %d desde el poste %c hacia el poste %c\n{}",n,desde,hacia);
hanoi(n - 1,auxiliar,desde,hacia);
}

fn () main-> i32 {
let n:i32 ;


print!("Ingrese el número de discos: ");
print!("%d{}",n);
if (n <= 0){
	print!("El número de discos debe ser mayor que 0.\n");
1
}
hanoi(n,A,B,C);
0
}

