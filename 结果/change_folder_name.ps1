# ȥ���ļ������ֵ�ǰ 4 ���ַ�
$path = Split-Path -Path $MyInvocation.MyCommand.Definition -Parent
$directories = Get-ChildItem -Path $path -Directory
foreach ($directory in $directories) {
    $directoryName = $directory.Name[4..($directory.Name.length-1)]  # ȥ���ļ������ֵ�ǰ 4 ���ַ�
    $convertNameType = [System.String]$directoryName -replace ' ', ''
    $directory
    $directoryName
    Rename-Item ($path + "\" +$directory) ($path + "\" +$convertNameType)
}