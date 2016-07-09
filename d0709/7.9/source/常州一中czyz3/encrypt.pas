var	s:ansistring;
        x,y,n,dir:longint;
	h,sa,tsa,v:array[0..530000]of longint;
	r:array[0..1,0..530000]of longint;

procedure re;
begin
	assign(input,'encrypt.in');reset(input);
	assign(output,'encrypt.out');rewrite(output);
end;

procedure wr;
begin
	close(input);close(output);
end;

procedure swap(var a,b:longint);var c:longint;begin c:=a;a:=b;B:=c;end;

function min(a,b:longint):longint;begin if a<b then exit(a);exit(b);end;

procedure make_sa;
var	i,j,m,p:longint;
begin
	m:=260;x:=0;y:=1;
	for i:=1 to n do begin r[x,i]:=ord(s[i]);inc(v[r[x,i]]);end;
	for i:=1 to m do inc(v[i],v[i-1]);
	for i:=1 to n do begin sa[v[r[x,i]]]:=i;dec(v[r[x,i]]);end;
	r[y,sa[1]]:=1;p:=1;
	for i:=2 to n do begin if r[x,sa[i]]<>r[x,sa[i-1]] then inc(p);r[y,sa[i]]:=p;end;
	j:=1;m:=p;swap(x,y);
	while p<n do
	begin
		p:=0;for i:=1 to m do v[i]:=0;
		for i:=n downto 1 do if sa[i]>j then begin inc(p);tsa[p]:=sa[i]-j;end;
		for i:=n downto n-j+1 do begin inc(p);tsa[p]:=i;end;
		for i:=1 to n do inc(v[r[x,i]]);
		for i:=1 to m do inc(v[i],v[i-1]);
		for i:=1 to n do begin sa[v[r[x,tsa[i]]]]:=tsa[i];dec(v[r[x,tsa[i]]]);end;
		r[y,sa[1]]:=1;p:=1;
		for i:=2 to n do
		begin if (r[x,sa[i]]<>r[x,sa[i-1]])or(r[x,sa[i]+j]<>r[x,sa[i-1]+j]) then inc(p);r[y,sa[i]]:=p;end;
		j:=j<<1;m:=p;swap(x,y);
	end;
end;

procedure make_he;
var	i,j,k:longint;
begin
	k:=0;
	for i:=1 to n do
	if r[x,i]=1 then h[r[x,i]]:=0 else
	begin
		j:=sa[r[x,i]-1];
		while (i+k<=n)and(j+k<=n)and(s[i+k]=s[j+k]) do inc(k);
		h[r[x,i]]:=k;if k>0 then dec(k);
	end;
end;

procedure start;
begin
	dir:=1;readln(s);n:=length(s);
	make_sa;make_he;
end;

procedure solve;
var	t,len,j,i:longint;
begin
	while dir<n do
	begin
		if dir=1 then begin write(-1,' ',ord(s[dir]),' ');inc(dir);continue;end;
		j:=dir;len:=0;t:=h[r[x,dir]];
		if r[x,dir]<>1 then
		for i:=r[x,dir] downto 2 do
		begin
			if (h[i]<len)or(h[i]=0) then break;
			t:=min(t,h[i]);
			if ((t>len)and(sa[i-1]<dir))or((sa[i-1]<j)and(t=len))then begin j:=sa[i-1];len:=t;end;
		end;
		t:=h[r[x,dir]+1];
		if r[x,dir]<>n then
		for i:=r[x,dir]+1 to n do
		begin
			if (h[i]<len)or(h[i]=0) then break;
			t:=min(t,h[i]);
			if ((t>len)and(sa[i]<dir))or((sa[i]<j)and(t=len))then begin j:=sa[i];len:=t;end;
		end;
		if len=0 then begin write(-1,' ',ord(s[dir]),' ');inc(dir);continue;end;
		write(len,' ',j-1,' ');dir:=dir+len;
	end;
	writeln;
end;

begin
	re;
	start;
	solve;
	wr;
end.
