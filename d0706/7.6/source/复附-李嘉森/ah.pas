const n=100000+10;
var fa,so,bro:array[0..n]of longint;
	tt,nn,b1,b2,b3,b4,b5:longint;
	sig,sum:array[0..n]of longint;
	ans,s1,s2:array[0..n]of longint;sz:longint;
	t1,t2:text;
procedure sort(f1,f2:longint);
var f3,f4,f5,f6:longint;
begin
	if f1>=f2 then exit;
	f3:=(f1+f2)div 2;
	sort(f1,f3);sort(f3+1,f2);
	for f4:=f1 to f3 do s1[f4]:=ans[f4];s1[f3+1]:=maxlongint;
	for f5:=f3+1 to f2 do s2[f5]:=ans[f5];s2[f2+1]:=maxlongint;
	f4:=f1;f5:=f3+1;
	for f6:=f1 to f2 do begin
		if s1[f4]<=s2[f5] then begin
			ans[f6]:=s1[f4];
			inc(f4);
		end else begin
			ans[f6]:=s2[f5];
			inc(f5);
		end;
	end;
end;
procedure dfs(f1:longint);
var f2,f3:longint;
begin
	f2:=so[f1];
	if f2=0 then begin
		if sig[f1]=-1 then sig[f1]:=-2;
		exit;
	end;
	while f2<>0 do begin
		dfs(f2);
		f2:=bro[f2];
	end;
	f2:=so[f1];f3:=0;
	while f2<>0 do begin
		if sig[f2]=0 then inc(f3);
		if sig[f2]=1 then dec(f3);
		f2:=bro[f2];
	end;
	sum[f1]:=f3;
	if f3>0 then sig[f1]:=0;
	if f3<0 then sig[f1]:=1;
	if f3=0 then sig[f1]:=-2;
end;
procedure dfs2(f1:longint);
var f2,f3:longint;
begin
	f2:=so[f1];
	if f2=0 then begin
		inc(sz);
		ans[sz]:=f1;
		exit;
	end;
	while f2<>0 do begin
		if (sig[f2]=-2)or((sig[f2]=1)and(sum[f2]=-1)) then dfs2(f2);
		f2:=bro[f2];
	end;
end;
procedure dfs3(f1:longint);
var f2,f3:longint;
begin
	f2:=so[f1];
	if f2=0 then begin
		if sig[f1]=-2 then begin
			inc(sz);
			ans[sz]:=f1;
		end;
		exit;
	end;
	while f2<>0 do begin
		if true then dfs3(f2);
		f2:=bro[f2];
	end;
end;
begin
	assign(t1,'ah.in');
	assign(t2,'ah.out');
	reset(t1);rewrite(t2);
	read(t1,tt);
	for b1:=1 to tt do begin
		read(t1,nn);
		bro[0]:=0;so[0]:=0;
		for b2:=1 to nn do begin
			so[b2]:=0;
			bro[b2]:=0;
			read(t1,fa[b2]);
		end;
		for b2:=1 to nn do begin
			bro[b2]:=so[fa[b2]];
			so[fa[b2]]:=b2;
		end;
		sig[0]:=-1;
		for b2:=1 to nn do read(t1,sig[b2]);
		dfs(0);
		ans[0]:=sig[0];
		sz:=0;
		if ans[0]=1 then begin
			writeln(t2,-1);
		
		
		end else if ans[0]=-2 then begin
			dfs2(0);
			write(t2,sz);
			sort(1,sz);
			for b3:=1 to sz do write(t2,' ',ans[b3]);
			writeln(t2);
		end else begin
			dfs3(0);
			write(t2,sz);
			sort(1,sz);
			for b3:=1 to sz do write(t2,' ',ans[b3]);
			writeln(t2);
		end;
	end;
	close(t1);close(t2);
end.
