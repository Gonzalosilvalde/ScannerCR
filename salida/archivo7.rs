fn factorial (i32  n) -> u64 {{
		if (n == 0 || n == 1){
			1
		}else{
				n * factorial(n - 1)}
		
	}
	
	fn () main-> i32 {
		let numero:i32 ;
		
		print!("Ingrese un número para calcular su factorial: ");let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");if (numero < 0){
			print!("No existe factorial para números negativos.\n");
		}else{
				print!("El factorial de %d es %llu\n{}",numero,factorial(numero));}
		0
	}
	
	