@ops@
identifier ops, fn;
@@
const struct net_device_ops ops = {
+#if LINUX_VERSION_IS_GEQ(5,13,0)
  .ndo_fill_forward_path = fn,
+#endif
  ...
};

@@
identifier ops.fn;
@@
+#if LINUX_VERSION_IS_GEQ(5,13,0)
int fn(...)
{
...
}
+#endif /* LINUX_VERSION_IS_GEQ(5,13,0) */
