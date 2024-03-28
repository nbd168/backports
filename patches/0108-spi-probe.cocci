@r@
identifier OPS;
identifier spi_driver_remove;
fresh identifier spi_driver_remove_wrap = "bp_" ## spi_driver_remove;
position p;
@@
struct spi_driver OPS@p = {
+#if LINUX_VERSION_IS_GEQ(5,18,0)
	.remove = spi_driver_remove,
+#else
+	.remove = spi_driver_remove_wrap,
+#endif
};

@@
identifier r.spi_driver_remove_wrap;
identifier r.spi_driver_remove;
@@
void spi_driver_remove(...) {...}
+#if LINUX_VERSION_IS_LESS(5,18,0)
+static int spi_driver_remove_wrap(struct spi_device *spi)
+{
+	spi_driver_remove(spi);
+
+	return 0;
+}
+#endif
