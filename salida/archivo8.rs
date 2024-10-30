const MAX_PRODUCTOS: usize = 100;
struct Producto {
	let id:i32 ,
	
	nombre: [char ;50],
	
	let cantidad:i32 ,
	
	let precio:f32 ,
	
}
fn agregarProducto (inventario: [Producto], i32  numProductos) {
	if (numProductos < MAX_PRODUCTOS){
		print!("ID del producto: ");let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");print!("Nombre del producto: ");let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");print!("Cantidad en stock: ");let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");print!("Precio: ");let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");numProductos ++ ;print!("Producto agregado exitosamente.\n");
	}else{
			print!("Inventario lleno, no se puede agregar más productos.\n");}
	
}

fn mostrarInventario (inventario: [Producto], i32  numProductos) {
	print!("\nInventario:\n");for i in 0.. numProductos{
		print!("ID: %d, Nombre: %s, Cantidad: %d, Precio: %.2f\n{}",inventario[i].id,inventario[i].nombre,inventario[i].cantidad,inventario[i].precio);
	}
}

fn buscarProducto (inventario: [Producto], i32  id, i32  numProductos) {
	let encontrado:i32 =0;
	
	for i in 0.. numProductos{
		if (inventario[i].id == id){
			print!("Producto encontrado - ID: %d, Nombre: %s, Cantidad: %d, Precio: %.2f\n{}",inventario[i].id,inventario[i].nombre,inventario[i].cantidad,inventario[i].precio);encontrado:=1;
			
			break;
			
			
		}
	}if (!(encontrado)){
		print!("Producto con ID %d no encontrado.\n{}",id);
	}
}

fn () main-> i32 {
	inventario: [Producto;MAX_PRODUCTOS];
	
	let numProductos:i32 =0;
	
	let opcion:i32 ;
	
	id;
	
	loop{
		print!("\nSistema de Gestión de Inventario\n");print!("1. Agregar producto\n2. Mostrar inventario\n3. Buscar producto\n4. Salir\n");print!("Seleccione una opción: ");let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");match (opcion){
			1 => {
				agregarProducto(inventario,&numProductos);
				
				break;
				
				
			}, 2 => {
				mostrarInventario(inventario,numProductos);
				
				break;
				
				
			}, 3 => {
				print!("Ingrese el ID del producto a buscar: ");let mut input = String::new();
				io::stdin()
				.read_line(&mut input)
				.expect("Failed to read line");buscarProducto(inventario,numProductos,id);
				
				break;
				
				
			}, 4 => {
				print!("Saliendo del programa.\n");break;
				
				
			}, _ => {
				print!("Opción inválida.\n");
			}}
		if(opcion != 4){
			break;
		}
	}0
}

