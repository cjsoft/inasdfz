var
   s:array[0..5100] of char;
   n,i,j,tmp:longint;
   ne:array[0..5100,0..5100] of longint;
   mx,ls:array[0..5100] of longint;

procedure setin;
begin
    assign(input,'encrypt.in');
    assign(output,'encrypt.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

procedure getnext(i:longint);
var j,k:longint;
begin
    j:=i;k:=-1;
    ne[i,j]:=-1;
    while (j<n) do
    begin
        if (k=-1) or (s[j]=s[k+i]) then
        begin
            inc(k);inc(j);
            ne[i,j]:=k;
        end
        else k:=ne[i,k+i];
    end;
    {for j:=0 to i-1 do write('  ');
    for j:=i to n do write(ne[i,j],' ');
    writeln;   }
end;

begin
    setin;
    n:=0;
    while not eoln do begin read(s[n]);inc(n);end;
    for i:=0 to n-1 do getnext(i);
    for i:=0 to n-1 do mx[i]:=0;
    for i:=0 to n-1 do
    begin
        for j:=0 to n-1 do
        if ne[i,j+1]>0 then
        begin
            tmp:=ne[i,j+1];
            if tmp>mx[j-tmp+1] then begin mx[j-tmp+1]:=tmp;ls[j-tmp+1]:=i;end;
        end;
    end;
    i:=0;
    while i<=n-1 do
    begin
        if mx[i]=0 then begin write(-1,' ',ord(s[i]),' ');i:=i+1;end
        else begin write(mx[i],' ',ls[i],' ');i:=i+mx[i];end;
    end;
    writeln;
    outit;
end.
