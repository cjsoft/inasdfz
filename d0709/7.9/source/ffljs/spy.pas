const n=3000;
function bitcount(f1:longint):longint;
var ans:longint;
begin
	ans:=0;
	while f1<>0 do begin
		f1:=f1-(f1 and(-f1));
		inc(ans);
	end;
	exit(ans);

end;
var a:array[0..n,0..n*2]of single;
	nn,b1,b2,b3,b4:longint;
	b,c:array[0..n]of int64;
	t1,t2:text;
procedure eqa(f1,f2:longint);
var g3:longint;
begin
	for g3:=0 to nn*2 -1 do a[f1,g3]:=a[f2,g3];
end;
begin
	assign(t1,'spy.in');reset(t1);
	assign(t2,'spy.out');rewrite(t2);
	read(t1,nn);
	for b1:=0 to nn-1 do begin
		for b2:=0 to nn-1 do begin
			if (bitcount(b2 and not b1 )and 1)=0 then begin
				a[b1,b2]:=1;
			
			
			end;
		end;
	end;
	{for b1:=0 to nn-1 do begin
		for b2:=0 to nn-1 do begin
			write(a[b1,b2]:0:0);
		end;
		writeln;
	end;}
	for b1:=0 to nn-1 do a[b1,b1+nn]:=1;
	for b1:=0 to nn-1 do begin
		if a[b1,b1]=0 then begin
			b2:=b1+1;
			while a[b2,b1]=0 do inc(b2);
			{a[n*2]:=a[b2];
			a[b2]:=a[b1];
			a[b1]:=a[n*2];}
			eqa(n*2,b2);
			eqa(b2,b1);
			eqa(b1,n*2);
		end;
		for b2:=2*nn-1 downto b1 do a[b1,b2]:=a[b1,b2]/a[b1,b1];
		for b2:=b1+1 to nn-1 do begin
			for b3:=nn*2-1 downto b1 do a[b2,b3]:=a[b2,b3]-a[b1,b3]*a[b2,b1]/a[b1,b1];
		end;
	end;
	{for b1:=0 to nn-1 do begin
		for b2:=0 to nn*2-1 do begin
			write(a[b1,b2]:3:0);
		end;
		writeln;
	end;}
	
	for b1:=nn-2 downto 0 do begin
		for b2:=b1+1 to nn-1 do begin
			for b3:=nn*2-1 downto b2 do begin
				a[b1,b3]:=a[b1,b3]-a[b1,b2]*a[b2,b3]/a[b2,b2];
			end;
		end;
	end;
	{for b1:=0 to nn-1 do begin
		for b2:=0 to nn*2-1 do begin
			write(a[b1,b2]*(nn/2):2:0);
		end;
		writeln;
	end;}
	fillchar(c,sizeof(c),0);
	for b1:=0 to nn-1 do read(t1,b[b1]);
	for b1:=0 to nn-1 do for b2:=0 to nn-1 do inc(c[b1],b[b2]*int64(round(a[b1,b2+nn]*nn/2)));
	//for b1:=0 to nn-1 do write(' ',c[b1]);
	for b1:=0 to nn-1 do c[b1]:=c[b1] div (nn div 2);
	write(t2,c[0]);
	for b1:=1 to nn-1 do write(t2,' ',c[b1]);
	writeln(t2);
	close(t1);
	close(t2);
end.