const n=100000+10;
var a:array[0..1,0..n]of longint;
	b:array[0..n]of integer;
	nn,mm,b1,b2,b3,b4,b5:longint;
	ans:int64;
	t1,t2:text;
begin
	assign(t1,'name.in');
	reset(t1);
	assign(t2,'name.out');
	rewrite(t2);
	read(t1,nn);
	for b1:=1 to nn do read(t1,a[0,b1]);
	for b1:=1 to nn do read(t1,a[1,b1]);
	for b1:=1 to nn do b[b1]:=0;
	read(t1,mm);
	for b1:=1 to mm do begin
		read(t1,b2,b3,b4);
		for b5:=b2 to b3 do if a[b[b5],b5]<=b4 then b[b5]:=b[b5] xor 1;
	end;
	ans:=0;
	for b1:=1 to nn do inc(ans,a[b[b1],b1]);
	writeln(t2,ans);
	close(t1);close(t2);
end.