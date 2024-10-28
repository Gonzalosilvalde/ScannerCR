fn () main-> i32 {
	let operador:char ;
	
	
	let num1:f64 ;
	
	num2:f64 ;
	
	resultado;
	
	
	print!("Introduce el primer número: ");
	let mut input = String::new();
	io::stdin()
	.read_line(&mut input)
	.expect("Failed to read line");
	print!("Introduce el operador (+, -, *, /): ");
	let mut input = String::new();
	io::stdin()
	.read_line(&mut input)
	.expect("Failed to read line");
	print!("Introduce el segundo número: ");
	let mut input = String::new();
	io::stdin()
	.read_line(&mut input)
	.expect("Failed to read line");
	match (operador){
		"+" => {
			resultado:=num1 + num2;
			
			
			break;
			
			
		}, "-" => {
			resultado:=num1 - num2;
			
			
			break;
			
			
		}, "*" => {
			resultado:=num1 * num2;
			
			
			break;
			
			
		}, "/" => {
			if (num2 != 0){
				resultado:=num1 / num2;
				
				
			}
			else{
					print!("Error: División por cero no permitida.\n");
				1}
			
			break;
			
			
		}, _ => {
			print!("Operador no válido.\n");
			1
		}}
	
	print!("Resultado: %.2f\n{}",resultado);
	0
}

