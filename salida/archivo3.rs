fn ordenarBurbuja (arr: [i32 ], i32  n) {
	for i in 0..1{
		for j in 0..1{
			if (arr[j] > arr[j + 1]){
				let temp:i32 =arr[j];
				
				arr[j]:=arr[j + 1];
				
				arr[j + 1]:=temp;
				
				
			}
		}
	}
}

fn () main-> i32 {
	let n:i32 ;
	
	print!("Introduce el número de elementos en el arreglo: ");let mut input = String::new();
	io::stdin()
	.read_line(&mut input)
	.expect("Failed to read line");arr: [i32 ;n];
	
	print!("Introduce los elementos del arreglo:\n");for i in 0.. n{
		let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");
	}ordenarBurbuja(arr,n);
	
	print!("Arreglo ordenado en orden ascendente:\n");for i in 0.. n{
		print!("%d {}",arr[i]);
	}print!("\n");0
}

