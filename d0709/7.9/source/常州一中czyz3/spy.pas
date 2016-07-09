var	a,b:array[0..1050000]of int64;
	c:array[0..20,0..1050000]of int64;
	n:longint;

procedure re;
begin
	assign(input,'spy.in');reset(input);
	assign(output,'spy.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure start;
var	i:longint;
begin
	readln(n);for i:=1 to n do read(b[i]);
end;

procedure solve(dir,dep:longint);
var	sl,sr:int64;
	len,i:longint;
begin
	if 1<<dep=n then begin a[dir]:=b[1];exit;end;
	sl:=b[n>>(dep+1)];sr:=b[n>>dep]-sl;len:=n>>(dep+1);
	for i:=1 to len do
	begin
		c[dep,i]:=b[i];
		b[i]:=(b[i]+b[i+len]-sr)>>1;
	end;
	solve(dir,dep+1);
	for i:=1 to len do
	b[i]:=(b[i+len]-c[dep,i]+sr)>>1;
	solve(dir+len,dep+1);
end;

procedure print;
var i:longint;
begin
	for i:=1 to n do write(a[i],' ');writeln;
end;

begin
	re;
	start;
	solve(1,0);
        print;
	wr;
end.
