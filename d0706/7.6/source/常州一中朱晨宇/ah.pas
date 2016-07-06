var t,i,n,wm,ym,k:longint;
begin
  assign(input,'ah.in'); assign(output,'ah.out');
  reset(input); rewrite(output);

  readln(t);
  for t:=1 to t do
  begin
    readln(n);
    for i:=1 to n do read(k);
    wm:=0; ym:=0;
    for i:=1 to n do
    begin
      read(k); if k=0 then inc(wm); if k=1 then inc(ym);
    end;
    if wm>=ym then begin writeln(0); continue; end;
    if ym>wm+1 then begin writeln(-1); continue; end;
    if ym=wm+1 then
    begin
      if (n-ym-wm) mod 2=0 then writeln(-1) else writeln(0);
    end;
  end;

  close(input); close(output);
end.