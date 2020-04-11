object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 528
  ClientWidth = 873
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
    Left = 696
    Top = 24
    Width = 32
    Height = 16
    Caption = 'Train'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 185
    Width = 99
    Height = 14
    Caption = 'Date of departure'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 601
    Top = 97
    Width = 61
    Height = 14
    Caption = 'Destination'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 601
    Top = 136
    Width = 100
    Height = 14
    Caption = 'Time of departure'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 601
    Top = 177
    Width = 107
    Height = 14
    Caption = 'Free places amount'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 88
    Top = 30
    Width = 131
    Height = 16
    Caption = 'Show all information'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 104
    Top = 89
    Width = 107
    Height = 14
    Caption = 'Needed destination'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 120
    Top = 136
    Width = 72
    Height = 14
    Caption = 'No later than'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 8
    Top = 156
    Width = 100
    Height = 14
    Caption = 'Time of departure'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 601
    Top = 56
    Width = 99
    Height = 14
    Caption = 'Date of departure'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ListBox1: TListBox
    Left = 305
    Top = 8
    Width = 281
    Height = 499
    ItemHeight = 13
    TabOrder = 0
  end
  object EditDay: TEdit
    Left = 721
    Top = 54
    Width = 40
    Height = 21
    TabOrder = 1
  end
  object EditPlace: TEdit
    Left = 722
    Top = 95
    Width = 141
    Height = 21
    TabOrder = 2
  end
  object EditHours: TEdit
    Left = 722
    Top = 133
    Width = 40
    Height = 21
    TabOrder = 3
  end
  object EditFreePlaces: TEdit
    Left = 722
    Top = 174
    Width = 141
    Height = 21
    TabOrder = 4
  end
  object ButtonAddOK: TButton
    Left = 682
    Top = 223
    Width = 105
    Height = 25
    Caption = 'OK'
    TabOrder = 5
    OnClick = ButtonAddOKClick
  end
  object ButtonClose: TButton
    Left = 737
    Top = 481
    Width = 96
    Height = 25
    Caption = 'Close'
    TabOrder = 6
    OnClick = ButtonCloseClick
  end
  object ButtonShowAllOK: TButton
    Left = 104
    Top = 52
    Width = 105
    Height = 25
    Caption = #1054#1050
    TabOrder = 7
    OnClick = ButtonShowAllOKClick
  end
  object EditNeededPlace: TEdit
    Left = 88
    Top = 109
    Width = 137
    Height = 21
    TabOrder = 8
  end
  object EditNeededHour: TEdit
    Left = 114
    Top = 156
    Width = 49
    Height = 21
    TabOrder = 9
  end
  object ButtonShowNeeded: TButton
    Left = 24
    Top = 223
    Width = 105
    Height = 25
    Caption = 'Search'
    TabOrder = 10
    OnClick = ButtonShowNeededClick
  end
  object ButtonSaveDialog: TButton
    Left = 56
    Top = 481
    Width = 89
    Height = 25
    Caption = 'Save'
    TabOrder = 11
    OnClick = ButtonSaveDialogClick
  end
  object ButtonOpenDialog: TButton
    Left = 151
    Top = 481
    Width = 93
    Height = 25
    Caption = 'Open'
    TabOrder = 12
    OnClick = ButtonOpenDialogClick
  end
  object EditMonth: TEdit
    Left = 767
    Top = 54
    Width = 42
    Height = 21
    TabOrder = 13
  end
  object EditYear: TEdit
    Left = 815
    Top = 54
    Width = 47
    Height = 21
    TabOrder = 14
  end
  object EditMinutes: TEdit
    Left = 768
    Top = 133
    Width = 40
    Height = 21
    TabOrder = 15
  end
  object EditNeededMinutes: TEdit
    Left = 169
    Top = 156
    Width = 50
    Height = 21
    TabOrder = 16
  end
  object ButtonOrderingTrain: TButton
    Left = 169
    Top = 223
    Width = 105
    Height = 25
    Caption = 'Ordering'
    TabOrder = 17
    OnClick = ButtonOrderingTrainClick
  end
  object EditSearchDay: TEdit
    Left = 113
    Top = 183
    Width = 50
    Height = 21
    TabOrder = 18
  end
  object EditSearchMonth: TEdit
    Left = 169
    Top = 183
    Width = 50
    Height = 21
    TabOrder = 19
  end
  object EditSearchYear: TEdit
    Left = 225
    Top = 183
    Width = 64
    Height = 21
    TabOrder = 20
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'txt'
    Filter = '|.txt'
    Left = 184
    Top = 431
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'txt'
    Filter = '|.txt'
    Left = 88
    Top = 431
  end
end
