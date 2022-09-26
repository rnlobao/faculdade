//
//  AddViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import Foundation
import UIKit

class AddViewController: UIViewController {
    @IBOutlet weak var registerButton: UIButton!
    var theActives: [String] = []
    @IBOutlet weak var pickerView: UIPickerView!
    
    @IBOutlet weak var tickerTF: UITextField!
    @IBOutlet weak var qtdTF: UITextField!
    @IBOutlet weak var priceTF: UITextField!
    @IBOutlet weak var dateTF: UITextField!
    
    override func viewDidLoad() {
        setupRegisterButton()
        setupPicker()
        theActives = ["Fii's", "Ações", "Criptoativos"]
    }
    
    func setupRegisterButton() {
        registerButton.layer.cornerRadius = 20
        registerButton.layer.shadowColor = UIColor.black.cgColor
        registerButton.layer.shadowOffset = CGSize(width: 0.0, height: 4.0)
        registerButton.layer.shadowRadius = 4.0
        registerButton.layer.shadowOpacity = 0.5
        registerButton.layer.masksToBounds = false
    }
    
    @IBAction func addButton(_ sender: Any) {
        print(pickerView.selectedRow(inComponent: 0))
    }
    func setupPicker() {
        pickerView.dataSource = self
        pickerView.delegate = self
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
