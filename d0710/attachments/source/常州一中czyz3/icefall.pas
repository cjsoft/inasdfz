var	n,casenum:longint;
	mo:int64;
	f:array[0..400,0..1,0..200,0..200]of int64;

procedure re;
begin
	assign(input,'icefall.in');reset(input);
	assign(output,'icefall.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure start;
begin
	read(n);readln(mo);
	fillchar(f,sizeof(f),0);
end;

function max(a,b:longint):longint;begin if a>b then exit(a);exit(b);end;

procedure solve;
var	i,j,k,t,r,l:longint;
begin
	//f[1,1,0,0]:=n;f[1,0,1,1]:=n;
	for j:=0 to 1 do
	for i:=0 to n-1 do f[1,j,1,i]:=1;
	{for i:=1 to n<<1-1 do//取走第i颗石子
	for j:=max(0,i-n) to i do//其中左岸取走了j颗
	begin
		if (j>0)and(j<n) then f[i+1,j+1,i-j,0]:=(f[i+1,j+1,i-j,0]+f[i,j,i-j,0]*((n-j)<<1))mod mo;
		if (j>0)and(i-j<n) then f[i+1,j,i-j+1,1]:=(f[i+1,j,i-j+1,1]+f[i,j,i-j,0]*(n-i+j))mod mo;
		if (i-j>0)and(i-j<n) then f[i+1,j,i-j+1,1]:=(f[i+1,j,i-j+1,1]+f[i,j,i-j,1]*(n-i+j)<<1)mod mo;
		if (i-j>0)and(j<n) then f[i+1,j+1,i-j,0]:=(f[i+1,j+1,i-j,0]+f[i,j,i-j,1]*(n-j))mod mo;
	end;}
	for i:=1 to n<<1-1 do
	for j:=0 to 1 do
	for k:=max(1,i-n) to i do
	begin
		r:=i-k;
		for t:=0 to n-k do
		begin
			if t<>0 then f[i+1,j,k+1,t-1]:=(f[i+1,j,k+1,t-1]+f[i,j,k,t])mod mo;
			if t<>n-k then f[i+1,j,k+1,t]:=(f[i+1,j,k+1,t]+f[i,j,k,t])mod mo;
			for l:=0 to n-r do
			f[i+1,j xor 1,r+1,l]:=(f[i+1,j xor 1,r+1,l]+f[i,j,k,t])mod mo;
		end;
	end;
	writeln((f[n<<1,0,n,0]+f[n<<1,1,n,0])mod mo);
	//writeln((f[n*2,n,n,0]+f[n*2,n,n,1])mod mo);
end;

begin
	re;
	readln(casenum);
	for casenum:=1 to casenum do
	begin
		start;solve;
	end;
	wr;
end.
