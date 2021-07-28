fn main() {
	let a=5;
	let b={
		let x=a+4;
		x
	};
	let c=sum(a,b);
	let d:bool=if c>10{true}else{false};
	if d{
		println!("{}>10",c);
	}else{
		println!("{}<=10",c);
	}
	let arr=[9;5];
	let mut i=0;
	while i!=arr.len(){
		print!("{} ",arr[i]);
		i+=1;
	}
	println!();
	for i in arr.iter(){
		print!("{} ",i);
	}
	println!();
	for i in 0..arr.len(){
		print!("{} ",arr[i]);
	}
	printHello(4);
}
fn sum(a:i32,b:i32)->i32{
	a+b
}


fn printHello(a:i32){
	if a>0{
		let mut temp=a;
		let str=String::from("Hello");
		while temp>0 {
			println!("{}",str);
			temp-=1;
		}
	}else{
		println!("参数错误!");
	}
}
