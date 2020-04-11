object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 548
  ClientWidth = 807
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 57
    Top = 42
    Width = 137
    Height = 13
    Caption = 'Input information from array'
  end
  object Label2: TLabel
    Left = 105
    Top = 310
    Width = 69
    Height = 13
    Caption = 'Add new node'
  end
  object Label3: TLabel
    Left = 80
    Top = 400
    Width = 114
    Height = 13
    Caption = 'Search or delete by key'
  end
  object Label4: TLabel
    Left = 69
    Top = 422
    Width = 18
    Height = 13
    Caption = 'Key'
  end
  object LabelFIO: TLabel
    Left = 80
    Top = 449
    Width = 141
    Height = 13
    Caption = '----------    ----------   ----------'
  end
  object Label5: TLabel
    Left = 47
    Top = 449
    Width = 27
    Height = 13
    Caption = 'Name'
  end
  object Label6: TLabel
    Left = 625
    Top = 42
    Width = 104
    Height = 13
    Caption = 'Information from tree'
  end
  object MemoKey: TMemo
    Left = 16
    Top = 61
    Width = 65
    Height = 197
    TabOrder = 0
  end
  object ButtonTreeFromArray: TButton
    Left = 101
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 1
    OnClick = ButtonTreeFromArrayClick
  end
  object MemoFIO: TMemo
    Left = 94
    Top = 61
    Width = 163
    Height = 197
    TabOrder = 2
  end
  object EditNewNodeKey: TEdit
    Left = 16
    Top = 329
    Width = 65
    Height = 21
    TabOrder = 3
  end
  object EditNewNodeFIO: TEdit
    Left = 87
    Top = 329
    Width = 170
    Height = 21
    TabOrder = 4
  end
  object ButtonAddNewNode: TButton
    Left = 101
    Top = 356
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 5
    OnClick = ButtonAddNewNodeClick
  end
  object EditKey: TEdit
    Left = 93
    Top = 419
    Width = 106
    Height = 21
    TabOrder = 6
  end
  object ButtonSearch: TButton
    Left = 45
    Top = 468
    Width = 75
    Height = 25
    Caption = 'Search'
    TabOrder = 7
    OnClick = ButtonSearchClick
  end
  object ButtonDelete: TButton
    Left = 149
    Top = 468
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 8
    OnClick = ButtonDeleteClick
  end
  object ButtonBalance: TButton
    Left = 470
    Top = 460
    Width = 99
    Height = 33
    Caption = 'Balance'
    TabOrder = 9
    OnClick = ButtonBalanceClick
  end
  object ButtonExit: TButton
    Left = 680
    Top = 460
    Width = 89
    Height = 33
    Caption = 'Exit'
    TabOrder = 10
    OnClick = ButtonExitClick
  end
  object TreeView: TTreeView
    Left = 280
    Top = 29
    Width = 289
    Height = 425
    Indent = 19
    TabOrder = 11
  end
  object ListBox: TListBox
    Left = 591
    Top = 61
    Width = 178
    Height = 345
    ItemHeight = 13
    TabOrder = 12
  end
  object ButtonWritePostOrder: TButton
    Left = 680
    Top = 421
    Width = 89
    Height = 33
    Caption = 'Write post-order'
    TabOrder = 13
    OnClick = ButtonWritePostOrderClick
  end
  object ButtonWritePreOrder: TButton
    Left = 585
    Top = 421
    Width = 89
    Height = 33
    Caption = 'Write pre-order'
    TabOrder = 14
    OnClick = ButtonWritePreOrderClick
  end
  object ButtonWriteInOrder: TButton
    Left = 585
    Top = 460
    Width = 89
    Height = 33
    Caption = 'Write in-order'
    TabOrder = 15
    OnClick = ButtonWriteInOrderClick
  end
  object ButtonDeleteBranch: TButton
    Left = 94
    Top = 499
    Width = 80
    Height = 30
    Caption = 'Delete Branch'
    TabOrder = 16
    OnClick = ButtonDeleteBranchClick
  end
end
