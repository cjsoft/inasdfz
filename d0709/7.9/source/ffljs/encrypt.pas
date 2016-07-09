const n=500000;
var st:ansistring;
	sa,h:array[0..n]of longint;
	mo:array[0..1,0..n*2]of longint;
	mm,nn,b1,b2,b3,b4,b5,si1,si2,k:longint;
	a,b,c:array[0..n]of longint;
	xdsh,xdsn,xdsa:array[0..n*2]of longint;szxds:longint;{h:min,n:sum,a:min sa}
	d1,d2,d3,d4:longint;go:longint;
	t1,t2:text;
function min(f1,f2:longint):longint;
begin
	if f1<=f2 then exit(f1) else exit(f2);	
end;
function max(f1,f2:longint):longint;
begin
	if f1>=f2 then exit(f1) else exit(f2);	
end;
function telln(f1,f2:longint):longint;
var f3,ans:longint;
begin
	f1:=f1+szxds;f2:=f2+szxds;f3:=1;ans:=0;
	while f1<=f2 do begin
		while (f1+f3*2<=f2+1)and(f1 mod (f3*2)=0) do f3:=f3*2;
		while (f1+f3>f2+1)or(f1 mod f3<>0) do f3:=f3 div 2;
		ans:=ans+xdsn[f1 div f3];
		f1:=f1+f3;
	end;
	exit(ans);
end;
procedure changesan(f1:longint);
begin
	f1:=(f1+szxds)div 2;
	while f1>=1 do begin
		xdsa[f1]:=min(xdsa[f1*2],xdsa[f1*2+1]);
		xdsn[f1]:=xdsn[f1*2]+xdsn[f1*2+1];
		f1:=f1 div 2;
	end;
end;
function tellh(f1,f2:longint):longint;
var f3,ans:longint;
begin
	f1:=f1+szxds;f2:=f2+szxds;f3:=1;ans:=xdsh[f1];
	while f1<=f2 do begin
		while (f1+f3*2<=f2+1)and(f1 mod (f3*2)=0) do f3:=f3*2;
		while (f1+f3>f2+1)or(f1 mod f3<>0) do f3:=f3 div 2;
		ans:=min(ans,xdsh[f1 div f3]);
		f1:=f1+f3;
	end;
	exit(ans);
end;
function tellsa(f1,f2:longint):longint;
var f3,ans:longint;
begin
	f1:=f1+szxds;f2:=f2+szxds;f3:=1;ans:=xdsa[f1];
	while f1<=f2 do begin
		while (f1+f3*2<=f2+1)and(f1 mod (f3*2)=0) do f3:=f3*2;
		while (f1+f3>f2+1)or(f1 mod f3<>0) do f3:=f3 div 2;
		ans:=min(ans,xdsa[f1 div f3]);
		f1:=f1+f3;
	end;
	exit(ans);
end;
function rangegetr(f1,f2:longint):longint;
var f3,ans:longint;
begin
	f1:=f1+szxds;f2:=f2+szxds;f3:=1;
	while (f1<=szxds*2-1)and(xdsh[f1]>=f2) do begin
		while (f1+f3*2<=szxds*2)and(f1 mod (f3*2)=0)and(xdsh[f1 div (f3 *2)]>=f2) do f3:=f3*2;
		while (f1+f3>szxds*2)or(f1 mod f3<>0)or(xdsh[f1 div f3]<f2) do f3:=f3 div 2;
		f1:=f1+f3;
	end;
	exit(f1-1-szxds);
end;
function rangegetl(f1,f2:longint):longint;
var f3,ans:longint;
begin
	f1:=f1+szxds;f2:=f2+szxds;f3:=1;
	while (f1>=szxds+1)and(xdsh[f1]>=f2) do begin
		while (f1-f3*2>=szxds)and((f1+1) mod (f3*2)=0)and(xdsh[f1 div (f3 *2)]>=f2) do f3:=f3*2;
		while (f1-f3<szxds)or((f1+1) mod f3<>0)or(xdsh[f1 div f3]<f2) do f3:=f3 div 2;
		f1:=f1-f3;
	end;
	exit(f1+2-szxds);
end;
function get(f1:longint):longint;
var g1:longint;
begin
	g1:=1;
	while g1<=szxds do begin
		if xdsn[g1*2]>=f1 then begin
			g1:=g1*2;
		end else begin
			f1:=f1-xdsn[g1*2];
			g1:=g1*2+1;
		end;
	end;
	exit(g1-szxds);
end;
procedure sort(f1:longint);
var g1,g2,g3,g4:longint;
begin
	for g1:=0 to max(nn,26) do b[g1]:=0;
	for g1:=1 to nn do inc(b[mo[si1,a[g1]+f1]]);
	for g1:=1 to max(nn,26) do b[g1]:=b[g1]+b[g1-1];
	for g1:=nn downto 1 do begin
		c[b[mo[si1,a[g1]+f1]]]:=a[g1];
		dec(b[mo[si1,a[g1]+f1]]);
	end;
	for g1:=1 to nn do a[g1]:=c[g1];
end;

begin
	assign(t1,'')
	readln(st);            fillchar(xdsa,sizeof(xdsa),$3F);fillchar(xdsh,sizeof(xdsh),$3F);
	nn:=length(st);     st:=st+'0';
	for b1:=1 to nn do begin
		mo[0,b1]:=ord(st[b1])-ord('a')+1;
	end;
	mm:=1;si2:=1;si1:=0;k:=0;
	while mm<nn do begin
		for b1:=1 to nn do a[b1]:=b1;
		sort(1 shl k);
		sort(0);
		mm:=1;
		mo[si2,a[1]]:=1;
		for b2:=2 to nn do begin
			if not((mo[si1,a[b2]]=mo[si1,a[b2-1]])and(mo[si1,a[b2]+1 shl k]=mo[si1,a[b2-1]+1 shl k])) then mm:=mm+1;
			mo[si2,a[b2]]:=mm;
		end;
		si1:=si1 xor 1;
		si2:=si2 xor 1;
		k:=k+1;
	end;
	for b1:=1 to nn do begin
		sa[mo[si1,b1]]:=b1;
		a[b1]:=mo[si1,b1];
	end;
	//for b1:=1 to nn do writeln(a[b1]);
	for b1:=1 to nn do begin
		//h[a[b1]]:=h[a[b1-1]]-1;
		//if h[a[b1]]<0 then h[a[b1]]:=0;
		b2:=h[a[b1-1]]-1;
		if b2<0 then b2:=0;

		if a[b1]>1 then while st[sa[a[b1]-1]+b2]=st[sa[a[b1]]+b2] do b2:=b2+1;
		h[a[b1]]:=b2;
	end;
	//for b1:=1 to nn do writeln(h[b1]);
	szxds:=1;
	while szxds<nn do szxds:=szxds*2;
	dec(szxds);
	for b1:=1 to nn do begin
		xdsh[b1+szxds]:=h[b1];
		xdsn[b1+szxds]:=0;
		xdsa[b1+szxds]:=nn+1;
	end;
	for b1:=szxds downto 1 do begin
		xdsh[b1]:=min(xdsh[b1*2],xdsh[b1*2+1]);
		xdsa[b1]:=min(xdsa[b1*2],xdsa[b1*2+1]);
		xdsn[b1]:=xdsn[b1*2]+xdsn[b1*2+1];
	end;go:=1;
	for b1:=1 to nn do begin
		if b1>=go then begin
			d1:=0;
			d2:=0;
			b3:=telln(1,a[b1]);
			if b3>0 then begin
				b4:=get(b3-1);
				d1:=tellh(b4+1,a[b1]);
			end else d1:=0;
			b4:=telln(1,nn);
			if b3<b4 then begin
				b4:=get(b3+1);
				d2:=tellh(a[b1]+1,b4);
			end else d2:=0;
			if d2>d1 then d1:=d2;
			if d1=0 then begin
				//to be done
				writeln('-1 ',ord(st[b1]));
				go:=b1+1;
			end else begin
				d3:=rangegetl(a[b1],d1)-1;writeln(d3,d4);
				d4:=rangegetr(a[b1],d1);
				writeln(d1,' ',tellsa(d3,d4)-1,' ');
				go:=b1+d1;
			end;
		end;
		xdsn[a[b1]+szxds]:=xdsn[a[b1]+szxds]+1;
		xdsa[a[b1]+szxds]:=b1;
		changesan(a[b1]);
	end;
end.





