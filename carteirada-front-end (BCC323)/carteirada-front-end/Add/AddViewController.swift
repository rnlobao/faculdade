//
//  AddViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import Foundation
import UIKit
import FirebaseFirestore
import FirebaseDatabase
import FirebaseAuth

struct Assets {
    let kind: Int
    let date: String
    let ticker: String
    let quantity: Double
    let price: Double
}

class AddViewController: UIViewController {
    
    @IBOutlet weak var registerButton: DefaultButton!
    @IBOutlet weak var pickerView: UIPickerView!
    @IBOutlet weak var tickerTF: DefaultTextField!
    @IBOutlet weak var qtdTF: DefaultTextField!
    @IBOutlet weak var priceTF: DefaultTextField!
    @IBOutlet weak var dateTF: DefaultTextField!
    
    
    var theActives: [String] = []
    
    let ref = Database.database().reference()
    var uid: String = ""

    
    override func viewDidLoad() {
        setupPicker()
        theActives = ["Fii's", "Ações", "Criptoativos"]
        setupDateTF()
        registerButton.configure(whatsInside: "Adicionar")
        uid = Auth.auth().currentUser!.uid
        setupToolBar()
    }
    
    private func writeData(active: Assets) {
        
        if active.kind == 0 {
            addingAssetsToDB(asset: active, kind: "fii")
        } else if active.kind == 1 {
            addingAssetsToDB(asset: active, kind: "acoes")
        } else if active.kind == 2 {
            addingAssetsToDB(asset: active, kind: "cripto")
        }
        
        var total = 0.0
        
        total += active.quantity * active.price
        
        ref.child("users").child(uid).child("assets").child("totalCarteira").observeSingleEvent(of: .value) { data in
            total += data.value as! Double
            self.ref.child("users").child(self.uid).child("assets").child("totalCarteira").setValue(total)
        }
        
        ref.observe(.childAdded) { data in
            let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
                self.dateTF.text = ""
                self.tickerTF.text = ""
                self.priceTF.text = ""
                self.qtdTF.text = ""
            }))
            self.present(alert, animated: true)
        }
    }
    
    private func addingAssetsToDB(asset: Assets, kind: String) {
        var total = 0.0
        ref.child("users").child(uid).child("assets").child(kind).childByAutoId().setValue(["data": asset.date, "ticker": asset.ticker, "quantity": asset.quantity, "price": asset.price])
        
        total += asset.quantity * asset.price
        
        ref.child("users").child(uid).child("assets").child(kind).child("inTotal").observeSingleEvent(of: .value) { data in
            total += data.value as! Double
            self.ref.child("users").child(self.uid).child("assets").child(kind).child("inTotal").setValue(total)
        }
    }
    
    @IBAction func addButton(_ sender: Any) {
        let active: Int = pickerView.selectedRow(inComponent: 0)
        let date: String = self.dateTF.text ?? ""
        let ticker: String = self.tickerTF.text ?? ""
        let quantity: Double = Double(qtdTF.text ?? "") ?? 0
        let price: Double = Double(priceTF.text ?? "") ?? 0.0
        
        let myAsset = Assets(kind: active, date: date, ticker: ticker, quantity: quantity, price: price)
        writeData(active: myAsset)
    }
    
    func setupPicker() {
        pickerView.dataSource = self
        pickerView.delegate = self
    }
    
    private func setupQtdTf() {
        qtdTF.keyboardType = .numberPad
        priceTF.keyboardType = .decimalPad
    }
    
    private func setupDateTF() {
        dateTF.delegate = self
        dateTF.keyboardType = .numberPad
    }
    
    func setupToolBar() {
        setupToolBarTicker()
        setupToolBarQtd()
        setupToolBarPrice()
        setupToolBarDate()
    }
    
    private func setupToolBarTicker() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemEmail = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardTicker))
        let nextButtonItemEmail = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldTicker))
        keyboardToolbar.items = [flexBarButton, closeButtonItemEmail, nextButtonItemEmail]
        tickerTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarQtd() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemUser = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardQtd))
        let nextButtonItemUser = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldQtd))
        keyboardToolbar.items = [flexBarButton, closeButtonItemUser, nextButtonItemUser]
        qtdTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarPrice() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemPW = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardPrice))
        let nextButtonItemPW = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldPrice))
        keyboardToolbar.items = [flexBarButton, closeButtonItemPW, nextButtonItemPW]
        priceTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarDate() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemconfirmPW = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardDate))
        keyboardToolbar.items = [flexBarButton, closeButtonItemconfirmPW]
        dateTF.inputAccessoryView = keyboardToolbar
    }
    
    @objc func closeKeyboardTicker() {
        tickerTF.endEditing(true)
    }
    
    @objc func closeKeyboardQtd() {
        qtdTF.endEditing(true)
    }
    
    @objc func closeKeyboardPrice() {
        priceTF.endEditing(true)
    }
    
    @objc func closeKeyboardDate() {
        dateTF.endEditing(true)
    }
    
    @objc func nextTextFieldTicker() {
        tickerTF.resignFirstResponder()
        qtdTF.becomeFirstResponder()
    }
    
    @objc func nextTextFieldQtd() {
        qtdTF.resignFirstResponder()
        priceTF.becomeFirstResponder()
    }
    
    @objc func nextTextFieldPrice() {
        priceTF.resignFirstResponder()
        dateTF.becomeFirstResponder()
    }
}

extension AddViewController: UIPickerViewDelegate, UIPickerViewDataSource {
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return theActives.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return theActives[row]
    }
}

extension AddViewController: UITextFieldDelegate {
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        if textField == dateTF {
            if (dateTF?.text?.count == 2) || (dateTF?.text?.count == 5) {
                if !(string == "") {
                    dateTF?.text = (dateTF?.text)! + "/"
                }
            }
            return !(textField.text!.count > 9 && (string.count ) > range.length)
        }
        else {
            return true
        }
    }
}
