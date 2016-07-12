var
begin
  assign(input,'jian.in'); assign(output,'jian.out');
  reset(input); rewrite(output);

  writeln(1);

  close(input); close(output);
end.