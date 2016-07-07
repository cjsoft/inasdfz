const n=40+2;sz=1 shl 22;
var a:array[0..n]of int64;
	nn,b1,b2,b3,b4,b5:longint;
	ll:longint;
	ch:char;
	my:int64;
	ans:int64;
	t1,t2:text;
procedure dfs(p1:int64;f1:longint);
begin
	if f1<nn then begin
		dfs(p1,f1+1);
		dfs(p1 xor a[f1],f1+1);
	end else begin
		for b1:=0 to 40-ll do begin
			if (((p1 shr b1)and(my))=my)and(((p1 shr b1)and (not(my)) and((1 shl ll)-1))=0) then begin
				inc(ans);
				//writeln(pp);
				exit;
			end;
		end;
	end;
end;
begin
	assign(t1,'elf.in');reset(t1);
	assign(t2,'elf.out');rewrite(t2);
	fillchar(a,sizeof(a),0);
	readln(t1,nn);
	for b1:=0 to nn-1 do begin
		for b2:=1 to 40 do begin
			read(t1,ch);
			if ch='1' then begin
				a[b1]:=a[b1]*2+1;
			end else if ch='0' then begin
				a[b1]:=a[b1]*2;
			end;
		end;
		readln(t1);
	end;
	readln(t1,ll);
	my:=0;
	for b1:=1 to ll do begin
		read(t1,ch);
		if ch='1' then my:=my*2+1 else my:=my*2;
	end;
	ans:=0;
	dfs(int64(0),0);
	writeln(t2,ans);
	close(t1);close(t2);
end.