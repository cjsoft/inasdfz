var	ans,bin,k:int64;
	n,m:longint;
	a:array[0..50]of int64;

procedure re;
begin
	assign(input,'elf.in');reset(input);
	assign(output,'elf.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

function pro(s:string):int64;
var	t,j:int64;
	i:longint;
begin
	j:=1;t:=0;
	for i:=length(s) downto 1 do
	begin
		if s[i]='1' then t:=t+j;j:=j<<1;
	end;
	exit(t);
end;

procedure start;
var	i:longint;
	s:string;
begin
	readln(n);
	for i:=1 to n do
	begin
		readln(s);a[i]:=pro(s);
	end;
	readln(m);
	readln(s);k:=pro(s);ans:=0;
	bin:=1;	for i:=1 to m do bin:=bin<<1;bin:=bin-1;
end;

procedure count(x:int64);
var	i:longint;
begin
	for i:=0 to 40-m do if (x>>i)and bin=k then begin inc(ans);exit;end;
end;

procedure dfs(dep:longint;x:int64);
begin
	if dep>n then count(x) else
	begin
		dfs(dep+1,x xor a[dep]);
		dfs(dep+1,x);
	end;
end;

begin
	re;
	start;
	dfs(1,0);
	writeln(ans);
	wr;
end.