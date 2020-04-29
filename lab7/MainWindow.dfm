object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 597
  ClientWidth = 476
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 48
    Top = 441
    Width = 114
    Height = 13
    Caption = 'Search or delete by key'
  end
  object Label4: TLabel
    Left = 37
    Top = 463
    Width = 18
    Height = 13
    Caption = 'Key'
  end
  object LabelGetALL: TLabel
    Left = 272
    Top = 21
    Width = 134
    Height = 13
    Caption = 'Information from hash table'
  end
  object Label1: TLabel
    Left = 54
    Top = 518
    Width = 92
    Height = 13
    Caption = 'First reached name'
  end
  object LabelName: TLabel
    Left = 30
    Top = 537
    Width = 141
    Height = 13
    Caption = '----------    ----------   ----------'
  end
  object Label2: TLabel
    Left = 30
    Top = 21
    Width = 137
    Height = 13
    Caption = 'Input information from array'
  end
  object Label5: TLabel
    Left = 16
    Top = 296
    Width = 175
    Height = 13
    Caption = 'Enter names to create random keys:'
  end
  object Label6: TLabel
    Left = 30
    Top = 40
    Width = 27
    Height = 13
    Caption = 'Keys:'
  end
  object Label7: TLabel
    Left = 119
    Top = 42
    Width = 36
    Height = 13
    Caption = 'Names:'
  end
  object MemoGetALL: TMemo
    Left = 216
    Top = 40
    Width = 241
    Height = 529
    Lines.Strings = (
      'MemoGetALL')
    TabOrder = 0
  end
  object EditKey: TEdit
    Left = 61
    Top = 460
    Width = 83
    Height = 21
    TabOrder = 1
  end
  object ButtonAddNewNode: TButton
    Left = 61
    Top = 410
    Width = 83
    Height = 25
    Caption = 'Add'
    TabOrder = 2
    OnClick = ButtonAddNewNodeClick
  end
  object ButtonSearchNode: TButton
    Left = 9
    Top = 487
    Width = 90
    Height = 25
    Caption = 'Search'
    TabOrder = 3
    OnClick = ButtonSearchNodeClick
  end
  object ButtonDeleteNode: TButton
    Left = 105
    Top = 487
    Width = 88
    Height = 25
    Caption = 'Delete'
    TabOrder = 4
    OnClick = ButtonDeleteNodeClick
  end
  object ButtonDeleteNegative: TButton
    Left = 105
    Top = 556
    Width = 88
    Height = 29
    Caption = 'Delete Negative'
    TabOrder = 5
    OnClick = ButtonDeleteNegativeClick
  end
  object ButtonClose: TButton
    Left = 8
    Top = 556
    Width = 91
    Height = 29
    Caption = 'Close'
    TabOrder = 6
    OnClick = ButtonCloseClick
  end
  object MemoKey: TMemo
    Left = 8
    Top = 59
    Width = 65
    Height = 197
    TabOrder = 7
  end
  object ButtonFromArray: TButton
    Left = 61
    Top = 264
    Width = 83
    Height = 25
    Caption = 'Add'
    TabOrder = 8
    OnClick = ButtonFromArrayClick
  end
  object MemoArrNames: TMemo
    Left = 87
    Top = 61
    Width = 106
    Height = 197
    TabOrder = 9
  end
  object MemoForNames: TMemo
    Left = 8
    Top = 315
    Width = 185
    Height = 89
    Lines.Strings = (
      'MemoForNames')
    TabOrder = 10
  end
end
