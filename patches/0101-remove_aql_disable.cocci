@aql_ops@
identifier aql_disable_write, aql_disable_read;
identifier simple_open, default_llseek;
@@
+#if LINUX_VERSION_IS_GEQ(4,10,0)
static const struct file_operations aql_enable_ops = {
	.write = aql_disable_write,
	.read = aql_disable_read,
	.open = simple_open,
	.llseek = default_llseek,
};
+#endif

@@
identifier aql_ops.aql_disable_write;
@@
+#if LINUX_VERSION_IS_GEQ(4,10,0)
aql_disable_write(...)
{
...
}
+#endif

@@
identifier aql_ops.aql_disable_read;
@@
+#if LINUX_VERSION_IS_GEQ(4,10,0)
aql_disable_read(...);
{
...
}
+#endif

@@
expression e;
@@
+#if LINUX_VERSION_IS_GEQ(4,10,0)
DEBUGFS_ADD_MODE(aql_enable, e);
+#endif
