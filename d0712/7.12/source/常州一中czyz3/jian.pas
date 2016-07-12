var	a:array[0..1010]of longint;
	v:array[0..1010]of boolean;
	ans,n,m:longint;

procedure re;
begin
	assign(input,'jian.in');reset(input);
	assign(output,'jian.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure check;
var	i,j:longint;
begin
	fillchar(v,sizeof(v),false);
	for i:=1 to n do if not v[(i+a[i])mod n] then v[(i+a[i])mod n]:=true else exit;
	for i:=1 to n do a[i+n]:=a[i];
	for i:=1 to n-1 do
	begin
		for j:=1 to n do
		begin
			if a[j]<a[j+i] then exit;
			if a[j]>a[j+i] then break;
		end;
		if a[j]=a[j+i] then exit;
	end;
	inc(ans);
end;

procedure dfs(dep,res:longint);
var	i:longint;
begin
	if (dep>n) then begin if res=0 then check;exit;end;
	for i:=res downto 0 do 
	begin
		a[dep]:=i;dfs(dep+1,res-i);
	end;
end;

begin
	re;
	readln(n,m);ans:=0;
	dfs(1,m);writeln(ans);
	wr;
end.