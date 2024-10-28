fn esPrimo (i32  num) -> bool {{
		if (num <= 1){
			1
		}
		for i in 2..= num{
			if (num % i == 0){
				0
			}
		}
		true
	}
	
	fn () main-> i32 {
		let numero:i32 ;
		
		
		print!("Introduce un número para verificar si es primo: ");
		let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");
		if (esPrimo(numero)){
			print!("%d es un número primo.\n{}",numero);
		}
		else{
				print!("%d no es un número primo.\n{}",numero);}
		
		0
	}
	
	