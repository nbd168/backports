@r@
identifier s,expr;
@@

struct genl_family s = {
+#if LINUX_VERSION_IS_GEQ(6,1,0)
	.resv_start_op = expr + 1,
+#endif
  ...
};
