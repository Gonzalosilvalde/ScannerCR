fn celsiusToFahrenheitAndKelvin (f32  celsius) {
	print!("Fahrenheit: %.2f\n{}",celsius * 9 / 5 + 32);print!("Kelvin: %.2f\n{}",celsius + 273.15);
}

fn fahrenheitToCelsiusAndKelvin (f32  fahrenheit) {
	print!("Celsius: %.2f\n{}",(fahrenheit - 32) * 5 / 9);print!("Kelvin: %.2f\n{}",(fahrenheit - 32) * 5 / 9 + 273.15);
}

fn kelvinToCelsiusAndFahrenheit (f32  kelvin) {
	print!("Celsius: %.2f\n{}",kelvin - 273.15);print!("Fahrenheit: %.2f\n{}",(kelvin - 273.15) * 9 / 5 + 32);
}

fn () main-> i32 {
	let opcion:i32 ;
	
	let temperatura:f32 ;
	
	print!("Conversor de Temperatura\n");print!("1. Celsius a Fahrenheit y Kelvin\n");print!("2. Fahrenheit a Celsius y Kelvin\n");print!("3. Kelvin a Celsius y Fahrenheit\n");print!("Seleccione una opción: ");let mut input = String::new();
	io::stdin()
	.read_line(&mut input)
	.expect("Failed to read line");print!("Ingrese la temperatura: ");let mut input = String::new();
	io::stdin()
	.read_line(&mut input)
	.expect("Failed to read line");match (opcion){
		1 => {
			celsiusToFahrenheitAndKelvin(temperatura);
			
			break;
			
			
		}, 2 => {
			fahrenheitToCelsiusAndKelvin(temperatura);
			
			break;
			
			
		}, 3 => {
			kelvinToCelsiusAndFahrenheit(temperatura);
			
			break;
			
			
		}, _ => {
			print!("Opción no válida.\n");
		}}
	0
}

