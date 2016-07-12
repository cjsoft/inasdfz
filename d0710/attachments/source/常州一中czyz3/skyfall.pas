const lim=25000000;
var	mini,q,num:array[0..lim+10]of longint;
        p:array[0..lim+10]of int64;
	prime:array[0..lim+10]of boolean;
	pn,bin:longint;

procedure re;
begin
	assign(input,'skyfall.in');reset(input);
	assign(output,'skyfall.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure preprocess;
var	i,j,now:longint;
begin
	fillchar(prime,sizeof(prime),false);pn:=0;
	for i:=2 to lim do
	begin
		if not prime[i] then begin inc(pn);p[pn]:=i;q[i]:=2;num[i]:=1;mini[i]:=i;end;
		for j:=1 to pn do
		if p[j]*i<=lim then
		begin
			now:=p[j]*i; prime[now]:=true;mini[now]:=p[j];
			if p[j]<mini[i] then begin q[now]:=q[i]*2;num[now]:=1;end else
			if p[j]=mini[i] then begin q[now]:=q[i] div (num[i]+1)*(num[i]+2);num[now]:=num[i]+1;end;
			if i mod p[j]=0 then break;
		end else break;
	end;
end;

procedure solve;
var	x,y,z,i,j,k:longint;
	ans:int64;
begin
	readln(x,y,z);q[1]:=1;
	bin:=1<<31-1;ans:=0;
	for i:=1 to x do
	for j:=1 to y do
	for k:=1 to z do
	ans:=(ans+q[i*j*k])and bin;
	writeln(ans);
end;

begin
	re;
	preprocess;
	solve;
	wr;
end.
