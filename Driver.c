#include <ntddk.h>

VOID ExampleDpcRoutine(PKDPC Dpc, PVOID DeferredContext, PVOID SystemArgument1, PVOID SystemArgument2);
VOID ExampleUnloadDriver(PDRIVER_OBJECT DriverObject);


NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);
    DriverObject->DriverUnload = ExampleUnloadDriver;
    PKDPC dpc = ExAllocatePool(NonPagedPool, sizeof(KDPC));
    if (dpc == NULL) {
        return STATUS_INSUFFICIENT_RESOURCES;
    }
    KeInitializeDpc(dpc, ExampleDpcRoutine, NULL);
    KeInsertQueueDpc(dpc, NULL, NULL);

    DbgPrint("Example Driver Loaded\n");
    return STATUS_SUCCESS;
}

VOID ExampleDpcRoutine(PKDPC Dpc, PVOID DeferredContext, PVOID SystemArgument1, PVOID SystemArgument2) {
    UNREFERENCED_PARAMETER(Dpc);
    UNREFERENCED_PARAMETER(DeferredContext);
    UNREFERENCED_PARAMETER(SystemArgument1);
    UNREFERENCED_PARAMETER(SystemArgument2);

    LARGE_INTEGER interval;
    interval.QuadPart = -10 * 10000; 
    KeDelayExecutionThread(KernelMode, FALSE, &interval);
    KeInsertQueueDpc(Dpc, NULL, NULL);

    DbgPrint("DPC Routine Executed\n");
}

VOID ExampleUnloadDriver(PDRIVER_OBJECT DriverObject) {
    UNREFERENCED_PARAMETER(DriverObject);
    DbgPrint("Example Driver Unloading\n");
}
